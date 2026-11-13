#include "fr08_content.h"
#include <stdexcept>
#include <cstring>
#include <cmath>
#include <algorithm>
namespace fr08 {
namespace {
struct Reader{
 const std::vector<uint8_t>&b;size_t p;
 void need(size_t n)const{if(p>b.size()||n>b.size()-p)throw std::runtime_error("Truncated original FR08 content");}
 uint8_t peek()const{need(1);return b[p];}uint8_t u8(){need(1);return b[p++];}
 uint16_t u16(){need(2);uint16_t x=b[p]|uint16_t(b[p+1])<<8;p+=2;return x;}
 uint32_t u24(){need(3);uint32_t x=b[p]|uint32_t(b[p+1])<<8|uint32_t(b[p+2])<<16;p+=3;return x;}
 uint32_t u32(){need(4);uint32_t x;memcpy(&x,b.data()+p,4);p+=4;return x;}
 float f32(){auto x=u32();float f;memcpy(&f,&x,4);return f;}
 void skip(size_t n){need(n);p+=n;}
 float parameter(){auto tag=u8();if(tag==0)return 0;if(tag==1)return 1;if(tag==2)return u8()/256.f;int sign=1,exponent=tag;if(tag>=246&&tag<=252){sign=-1;exponent=255-tag;}if(exponent>=3&&exponent<=9){float value=u8();for(int j=3;j<exponent;j++)value=(float)((double)value*.1);return sign*value;}uint32_t bits=uint32_t(tag)<<24;bits|=uint32_t(u8())<<16;bits|=uint32_t(u8())<<8;bits|=u8();float f;memcpy(&f,&bits,4);return f;}
};
void insist(bool condition,const char*message){if(!condition)throw std::runtime_error(message);}
}
Content Content::parse(const std::vector<uint8_t>&image,uint32_t offset){
 Content c;c.sourceBegin=offset;Reader r{image,offset};uint32_t parameterCount=0;
 while(r.peek()!=0){insist(c.nodes.size()<100000,"Node count limit");Node n={};n.id=(uint32_t)c.nodes.size()+1;n.group=r.u8();n.op=r.u8();n.flags=(int8_t)r.u8();n.type=r.u8();n.count=r.u8();n.aux=r.u8();n.reserved=r.u16();auto a=(int16_t)r.u16(),b=(int16_t)r.u16();n.linkA=a?(int32_t)n.id+a:0;n.linkB=b?(int32_t)n.id+b:0;n.parameterOffset=parameterCount;parameterCount+=n.count;c.nodes.push_back(n);}
 r.skip(4);for(auto*roots:{&c.textureRoots,&c.sceneRoots}){for(uint32_t id;(id=r.u32())!=0;){insist(id<=c.nodes.size(),"Invalid root node");roots->push_back(id);}}
 while(true){r.need(4);uint32_t marker;memcpy(&marker,image.data()+r.p,4);if(marker==0x01010101){r.skip(4);break;}Event e={};e.flags=r.u8();e.kind=r.u8();auto group=r.u16();e.group=group&0x3fff;e.groupFlags=group&0xc000;e.start=r.f32();e.end=r.f32();e.duration=r.f32();insist(std::isfinite(e.start)&&std::isfinite(e.end)&&e.end>=e.start,"Invalid original timeline event");c.events.push_back(e);insist(c.events.size()<100000,"Event count limit");}
 std::vector<uint8_t>keyCounts;uint16_t group=0;
 while(r.peek()!=0xff){uint8_t n=r.u8(),packed=r.u8();uint16_t node=r.u16();if(n==0){group=node;c.groupCount++;continue;}Channel channel={};channel.group=group;channel.node=node;channel.field=packed&63;channel.mode=packed>>6;insist(node>0&&node<=c.nodes.size()&&channel.field<c.nodes[node-1].count,"Invalid curve field binding");c.channels.push_back(channel);keyCounts.push_back(n);}
 r.skip(4);c.keyCount=r.u32();insist(c.keyCount<1000000,"Key count limit");std::vector<float>values(c.keyCount);std::vector<int16_t>times(c.keyCount);for(auto&v:values){uint32_t bits=r.u24()<<8;memcpy(&v,&bits,4);}for(auto&t:times)t=(int16_t)r.u16();uint32_t k=0;for(size_t i=0;i<c.channels.size();i++){auto&channel=c.channels[i];for(unsigned j=0;j<keyCounts[i];j++){insist(k<c.keyCount,"Curve keys overflow");Key key={};key.time=times[k];key.value=values[k];channel.keys.push_back(key);k++;}}insist(k==c.keyCount,"Curve key count mismatch");
 while(r.peek()!=0xff){CustomTable table;table.tag=r.u8();size_t begin=r.p;do{r.skip(2);}while(r.peek()!=0);table.data.assign(image.begin()+begin,image.begin()+r.p);r.skip(1);c.tables.push_back(std::move(table));insist(c.tables.size()<10000,"Custom table count limit");}
 r.skip(2);while(r.peek()!=0xff){c.parameters.push_back(r.parameter());insist(c.parameters.size()<=parameterCount,"Original parameter count overflow");}insist(c.parameters.size()==parameterCount,"Original parameter count mismatch");r.skip(4);
 while(r.peek()!=0){std::string s;for(uint8_t ch;(ch=r.u8())!=0;)s.push_back((char)ch);c.strings.push_back(std::move(s));insist(c.strings.size()<10000,"String count limit");}r.skip(1);c.sourceEnd=(uint32_t)r.p;
 for(const auto&n:c.nodes)insist(n.linkA>=0&&n.linkA<=(int32_t)c.nodes.size()&&n.linkB>=0&&n.linkB<=(int32_t)c.nodes.size(),"Invalid relative node link");c.prepareCurves();return c;
}
void Content::prepareCurves(){
 for(auto&ch:channels){int endpointMode=ch.mode;for(size_t i=0;i+1<ch.keys.size();i++){
  auto&a=ch.keys[i];const auto&b=ch.keys[i+1];float y1=a.value,y2=b.value,t1=a.time,t2=b.time;
  float y0=i?ch.keys[i-1].value:(endpointMode==2?y1-(y2-y1):y1),t0=i?ch.keys[i-1].time:t1-(t2-t1);
  float y3=i+2<ch.keys.size()?ch.keys[i+2].value:(endpointMode==2?y2+(y2-y1):y2),t3=i+2<ch.keys.size()?ch.keys[i+2].time:t2+(t2-t1);
  if(t2<t1+1e-10)endpointMode=0;
  if(ch.mode==0){a.coefficients={(float)y1,(float)(y2-y1),0,0};}
  else if(ch.mode==1||ch.mode==2){float m0=(y2-y0)/(1-(t0-t1)/(t2-t1)),m1=(y3-y1)/((t3-t1)/(t2-t1));a.coefficients={(float)y1,(float)m0,(float)(3*(y2-y1)-2*m0-m1),(float)(2*(y1-y2)+m1+m0)};}
 }
 }
}
float Content::evaluate(size_t channel,float normalizedTime)const{
 const auto&ch=channels.at(channel);if(ch.keys.size()<2)return 0;
 float originalProduct=normalizedTime*1000.f;int tick=(int)std::nearbyint(originalProduct);float storedProduct=originalProduct;
 if(tick<=ch.keys.front().time)return ch.keys.front().value;if(tick>=ch.keys.back().time)return ch.keys.back().value;
 for(size_t i=0;i+1<ch.keys.size();i++){const auto&a=ch.keys[i];const auto&b=ch.keys[i+1];if(tick<b.time){if(a.time==b.time)return a.value;float u=(storedProduct-a.time)/(b.time-a.time);return(float)(((u*a.coefficients[3]+a.coefficients[2])*u+a.coefficients[1])*u+a.coefficients[0]);}}
 return 0;
}
}
