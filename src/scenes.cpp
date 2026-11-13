#include "demo.h"
namespace {
constexpr float pi=XM_PI;
XMFLOAT3 v3(XMVECTOR v){XMFLOAT3 p;XMStoreFloat3(&p,v);return p;}
XMFLOAT3 add(XMFLOAT3 a,XMFLOAT3 b){return {a.x+b.x,a.y+b.y,a.z+b.z};}
XMFLOAT3 sub(XMFLOAT3 a,XMFLOAT3 b){return {a.x-b.x,a.y-b.y,a.z-b.z};}
XMFLOAT3 mul(XMFLOAT3 a,float b){return {a.x*b,a.y*b,a.z*b};}
XMFLOAT3 norm(XMFLOAT3 a){return v3(XMVector3Normalize(XMLoadFloat3(&a)));}
void tri(std::vector<Vertex>&v,XMFLOAT3 a,XMFLOAT3 b,XMFLOAT3 c,XMFLOAT3 na,XMFLOAT3 nb,XMFLOAT3 nc,XMFLOAT2 ua,XMFLOAT2 ub,XMFLOAT2 uc){v.push_back({a,na,ua,{1,1,1,1}});v.push_back({b,nb,ub,{1,1,1,1}});v.push_back({c,nc,uc,{1,1,1,1}});}
template<class F> Range param(std::vector<Vertex>&v,int nx,int ny,F f,bool smooth=true){Range r{(UINT)v.size(),0};auto normal=[&](float u,float w){float e=.0002f;auto p=f(u,w),q=f(u+e,w),s=f(u,w+e);auto x=sub(q,p),y=sub(s,p);return norm(v3(XMVector3Cross(XMLoadFloat3(&x),XMLoadFloat3(&y))));};for(int y=0;y<ny;y++)for(int x=0;x<nx;x++){float u=float(x)/nx,w=float(y)/ny,du=1.f/nx,dw=1.f/ny;auto a=f(u,w),b=f(u+du,w),c=f(u+du,w+dw),d=f(u,w+dw);auto na=normal(u,w),nb=normal(u+du,w),nc=normal(u+du,w+dw),nd=normal(u,w+dw);if(!smooth){auto ba=sub(b,a),ca=sub(c,a);na=nb=nc=nd=norm(v3(XMVector3Cross(XMLoadFloat3(&ba),XMLoadFloat3(&ca))));}tri(v,a,b,c,na,nb,nc,{u,w},{u+du,w},{u+du,w+dw});tri(v,a,c,d,na,nc,nd,{u,w},{u+du,w+dw},{u,w+dw});}r.count=(UINT)v.size()-r.first;return r;}
float rnd(int i){return std::fmod(std::sin(i*127.1f+311.7f)*43758.5453f,1.f)*.5f+.5f;}
}
void World::build(){
 vertices.reserve(250000);
 cube={(UINT)vertices.size(),0};
 const XMFLOAT3 ns[]={{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
 for(auto n:ns){XMVECTOR nn=XMLoadFloat3(&n),up=std::abs(n.y)>.5f?XMVectorSet(0,0,1,0):XMVectorSet(0,1,0,0);auto uu=XMVector3Cross(up,nn),vv=XMVector3Cross(nn,uu);auto p=[&](float u,float v){return v3(nn*.5f+uu*u+vv*v);};tri(vertices,p(-.5f,-.5f),p(.5f,-.5f),p(.5f,.5f),n,n,n,{0,1},{1,1},{1,0});tri(vertices,p(-.5f,-.5f),p(.5f,.5f),p(-.5f,.5f),n,n,n,{0,1},{1,0},{0,0});}cube.count=(UINT)vertices.size()-cube.first;
 sphere=param(vertices,48,24,[](float u,float v){float a=u*2*pi,b=(v-.5f)*pi;return XMFLOAT3{cosf(a)*cosf(b),sinf(b),sinf(a)*cosf(b)};});
 cylinder=param(vertices,40,1,[](float u,float v){float a=u*2*pi;return XMFLOAT3{cosf(a),v-.5f,sinf(a)};});
 cone=param(vertices,40,1,[](float u,float v){float a=u*2*pi,r=1-v;return XMFLOAT3{cosf(a)*r,v-.5f,sinf(a)*r};});
 torus=param(vertices,64,16,[](float u,float v){float a=u*2*pi,b=v*2*pi,r=1+.12f*cosf(b);return XMFLOAT3{cosf(a)*r,.12f*sinf(b),sinf(a)*r};});
 plane=param(vertices,1,1,[](float u,float v){return XMFLOAT3{(u-.5f),0,-(v-.5f)};});
 arch=param(vertices,32,4,[](float u,float v){float a=u*pi;return XMFLOAT3{cosf(a)*(1+v*.13f),sinf(a)*(1+v*.13f),0};});
 gear=param(vertices,128,4,[](float u,float v){float a=u*2*pi,r=.92f+.10f*(cosf(a*16)>.0f?1.f:-1.f);return XMFLOAT3{r*cosf(a),v*.24f-.12f,r*sinf(a)};},false);
 knot=param(vertices,180,16,[](float u,float v){auto path=[](float a){float r=2+.7f*cosf(a*3);return XMFLOAT3{r*cosf(a*2),.85f*sinf(a*3),r*sinf(a*2)};};float a=u*2*pi,b=v*2*pi;auto p=path(a),q=path(a+.001f);auto tangent=norm(sub(q,p));auto nn=norm(XMFLOAT3{tangent.z,0,-tangent.x});auto bb=v3(XMVector3Cross(XMLoadFloat3(&tangent),XMLoadFloat3(&nn)));return add(p,add(mul(nn,.32f*cosf(b)),mul(bb,.32f*sinf(b))));});
 auto put=[&](int s,Range mesh,XMFLOAT3 p,XMFLOAT3 scale,int mat,XMFLOAT4 tint=XMFLOAT4{1,1,1,1},XMFLOAT3 rot=XMFLOAT3{0,0,0},int motion=0,float seed=0){Object o;o.mesh=mesh;XMStoreFloat4x4(&o.world,XMMatrixScaling(scale.x,scale.y,scale.z)*XMMatrixRotationRollPitchYaw(rot.x,rot.y,rot.z)*XMMatrixTranslation(p.x,p.y,p.z));o.material=mat;o.tint=tint;o.motion=motion;o.seed=seed;scenes[s].objects.push_back(o);};
 auto box=[&](int s,XMFLOAT3 p,XMFLOAT3 scale,int mat,XMFLOAT4 c=XMFLOAT4{1,1,1,1}){put(s,cube,p,scale,mat,c);};
 scenes[0].name=".the .product / industrial";scenes[0].fog={.14f,.19f,.22f};scenes[0].density=.008f;
 box(0,{0,-.3f,0},{180,.6f,180},0,{.65f,.72f,.75f,1});
 // Cylindrical industrial plant, twin chimneys, pipelines and chain-link perimeter.
 put(0,cylinder,{0,4.5f,0},{6,9,6},2,{.42f,.48f,.48f,1});put(0,cone,{0,9.8f,0},{6.8f,1.6f,6.8f},3);
 for(float y:{.3f,2.5f,7.5f,9.f})put(0,torus,{0,y,0},{6.05f,2,6.05f},3);
 for(int k=0;k<2;k++){float x=k?2.5f:-2.5f;put(0,cylinder,{x,14,0},{1.25f,11,1.25f},3);for(float y:{10.f,13.f,17.f,19.f})put(0,torus,{x,y,0},{1.32f,1,1.32f},3);put(0,cylinder,{x,19.6f,0},{1.4f,.5f,1.4f},3,{.2f,.22f,.22f,1});}
 for(int i=0;i<18;i++){float a=i*2*pi/18;box(0,{6.05f*cosf(a),4.6f,6.05f*sinf(a)},{.12f,8,.12f},3);}
 box(0,{0,3.5f,-5.98f},{2.7f,3.6f,.15f},3,{.2f,.3f,.29f,1});box(0,{0,5.8f,-6.12f},{3,.8f,.05f},5,{.6f,.72f,.15f,1});
 for(int i=0;i<18;i++){float z=-28+i*3.2f;for(float x:{-17.f,17.f}){put(0,cylinder,{x,2.5f,z},{.07f,5,.07f},3);box(0,{x,2.3f,z},{.02f,4.4f,3.2f},6,{.5f,.5f,.48f,1});}}
 for(int i=0;i<12;i++){float x=-17+i*3.1f;put(0,cylinder,{x,2.5f,28},{.07f,5,.07f},3);box(0,{x,2.3f,28},{3.1f,4.4f,.02f},6);}
 for(int k=0;k<6;k++){float x=-35+k*13.f;box(0,{x,3,35},{10,6,8},2,{.48f,.46f,.4f,1});put(0,cone,{x,7,35},{7,3,6},3);}
 for(int k=0;k<10;k++){float z=-30+k*6.f;for(float x:{-22.f,22.f}){put(0,cylinder,{x,5,z},{.12f,10,.12f},3);put(0,sphere,{x,10,z},{.35f,.35f,.35f},5,{1,.6f,.2f,1});}}
 // Medieval fortress and courtyard, with a traversable vaulted stone corridor.
 scenes[1].name="stone / the castle";scenes[1].fog={.16f,.18f,.19f};scenes[1].density=.006f;
 box(1,{0,-1,0},{250,2,250},7,{.4f,.42f,.32f,1});box(1,{0,-.1f,0},{48,.25f,64},1);
 for(float x:{-20.f,20.f})for(float z:{-24.f,24.f}){put(1,cylinder,{x,8,z},{5,16,5},1);put(1,cone,{x,19,z},{6,7,6},8,{.35f,.2f,.13f,1});for(int i=0;i<12;i++){float a=i*2*pi/12;box(1,{x+4.8f*cosf(a),16,z+4.8f*sinf(a)},{1.3f,2,1.3f},1);}}
 for(float x:{-20.f,20.f})box(1,{x,5,0},{3,10,48},1);
 for(float z:{-24.f,24.f}){box(1,{-12,5,z},{13,10,3},1);box(1,{12,5,z},{13,10,3},1);box(1,{0,9,z},{12,3,3},1);}
 for(int k=0;k<19;k++)for(float x:{-20.f,20.f})box(1,{x,11,-22+k*2.5f},{3,2,1.25f},1);
 box(1,{0,10,9},{15,20,18},1);put(1,cone,{0,23,9},{12,8,14},8,{.28f,.18f,.15f,1});
 for(int k=0;k<9;k++){float z=-21+k*5;for(float x:{-8.f,8.f}){put(1,cylinder,{x,4,z},{.55f,8,.55f},1);put(1,torus,{x,.4f,z},{.85f,2,.85f},1);}
 put(1,arch,{0,7.5f,z},{8,4,1},1);box(1,{0,11.8f,z},{17,.5f,5},1);}
 for(int k=0;k<8;k++)for(float x:{-8.f,8.f}){float z=-19+k*5;box(1,{x,4,z},{.2f,8,5},1);put(1,sphere,{x*.96f,5,z},{.18f,.4f,.18f},5,{1,.4f,.08f,1});}
 // Long blue-brick passage with repeating vaulted ribs, stained-glass insets.
 scenes[3].name="passage / blue stone";scenes[3].fog={.045f,.09f,.13f};scenes[3].density=.011f;
 box(3,{0,-.2f,0},{8,.4f,180},0,{.38f,.5f,.6f,1});
 for(float x:{-4.f,4.f})box(3,{x,3.5f,0},{.5f,7,180},1,{.48f,.61f,.7f,1});box(3,{0,7,0},{8,.5f,180},1,{.4f,.5f,.6f,1});
 for(int i=0;i<36;i++){float z=-86+i*5.f;put(3,arch,{0,4,z},{3.8f,2.7f,1},1,{.6f,.65f,.67f,1});for(float x:{-3.7f,3.7f}){box(3,{x,2,z},{.35f,4,.45f},1);put(3,torus,{x*.99f,3.6f,z+1.6f},{.8f,1,.8f},3,{.5f,.32f,.15f,1},{0,0,pi/2});put(3,sphere,{x*.97f,3.6f,z+1.6f},{.03f,.58f,.58f},9,{.8f,.5f,.26f,1});put(3,sphere,{x*.9f,5.5f,z},{.12f,.3f,.12f},5,{1,.54f,.2f,1});}}
 // Reorder the reconstruction to the seven sets seen in the original capture.
 Scene industrial=std::move(scenes[0]),castle=std::move(scenes[1]),passage=std::move(scenes[3]);
 for(auto&s:scenes)s=Scene{};
 scenes[0]=std::move(passage);scenes[0].name="01 / the passage";
 scenes[1]=std::move(castle);scenes[1].name="02 / the castle";scenes[1].fog={.22f,.115f,.08f};
 scenes[5]=std::move(industrial);scenes[5].name="06 / industrial towers";
 // Circular valve wheels on the opening corridor walls.
 for(int i=0;i<20;i++)for(float x:{-3.55f,3.55f}){float z=-70+i*7.f;put(0,torus,{x,3.5f,z},{1,1,1},3,{.6f,.4f,.2f,1},{0,0,pi/2});for(int k=0;k<4;k++)put(0,cylinder,{x,3.5f,z},{.045f,1.9f,.045f},3,{.6f,.4f,.2f,1},{pi*k/4,0,0});}
 // Terrain and bare trees approach the fortress. The walls remain actual 3D geometry.
 auto terrain=param(vertices,100,100,[](float u,float v){float x=(u-.5f)*300,z=(v-.5f)*300;float outside=std::min(1.f,std::max(std::abs(x)-25,std::abs(z)-30)/20);float y=(sinf(x*.055f)*cosf(z*.043f)*7+sinf(z*.08f)*3)*std::max(0.f,outside);return XMFLOAT3{x,y-.6f,z};});put(1,terrain,{0,0,0},{1,1,1},7,{.8f,.72f,.33f,1});
 for(int i=0;i<45;i++){float x=(rnd(i*3)-.5f)*130,z=-35-rnd(i*3+1)*65;float h=6+rnd(i*3+2)*6;if(std::abs(x)<8)continue;put(1,cylinder,{x,h*.5f,z},{.45f,h,.45f},10);for(int j=0;j<5;j++){float a=j*2*pi/5;put(1,cylinder,{x+cosf(a)*1.5f,h*.75f,z+sinf(a)*1.5f},{.15f,4,.15f},10,{.6f,.5f,.3f,1},{sinf(a)*.75f,0,cosf(a)*.75f});put(1,plane,{x+cosf(a)*2,h+.5f,z+sinf(a)*2},{5,1,5},11,{.8f,.65f,.2f,1},{pi/2,a,0});}}
 box(1,{0,3.8f,-25.55f},{10,7.6f,.4f},10,{.65f,.38f,.16f,1});put(1,sphere,{0,7.4f,-25.5f},{5,4,.3f},10,{.65f,.38f,.16f,1});put(1,arch,{0,7.4f,-26},{5.2f,4.2f,1},1,{.7f,.62f,.5f,1});
 for(int k=0;k<15;k++){float a=.1f+(pi-.2f)*k/14;put(1,torus,{5.8f*cosf(a),7.5f+4.7f*sinf(a),-26.4f},{.6f,.6f,.6f},3,{.85f,.67f,.28f,1},{0,0,a});}
 // Fan room: broad perforated bases carry smoothly twisted, rotating impellers.
 scenes[2].name="03 / turbine hall";scenes[2].fog={.035f,.055f,.055f};scenes[2].density=.012f;
 box(2,{0,-.3f,0},{24,.6f,95},12);for(float x:{-12.f,12.f})box(2,{x,6,0},{.7f,12,95},3,{.35f,.4f,.36f,1});box(2,{0,12,0},{24,.5f,95},3);
 auto blade=param(vertices,36,14,[](float u,float v){float a=u*2*pi+v*1.8f;float r=.2f+v*3.1f;float y=3*(1-v)+sinf(u*6*pi)*v*.55f;return XMFLOAT3{r*cosf(a),y,r*sinf(a)};});
 for(int i=0;i<14;i++){float z=-40+i*6;float x=i%2?6.f:-6.f;put(2,cylinder,{x,.2f,z},{3.7f,.5f,3.7f},3,{.7f,.65f,.4f,1});put(2,torus,{x,.5f,z},{3.65f,1,3.65f},3,{.8f,.75f,.4f,1});put(2,blade,{x,.6f,z},{1,1,1},3,{.55f,.58f,.52f,1},{},3,(float)i);for(int k=0;k<24;k++){float a=k*2*pi/24;put(2,sphere,{x+3.6f*cosf(a),.45f,z+3.6f*sinf(a)},{.09f,.09f,.09f},3,{.12f,.12f,.1f,1});}}
 box(2,{0,6,47.5f},{24,12,.5f},3);box(2,{0,6,-47.5f},{24,12,.5f},3);
 // Circular brick shaft with successive brass iris grilles.
 scenes[3].name="04 / the brick shaft";scenes[3].fog={.055f,.04f,.045f};scenes[3].density=.014f;
 auto tube=param(vertices,80,80,[](float u,float v){float a=u*2*pi;return XMFLOAT3{5*cosf(a),5+5*sinf(a),(v-.5f)*180};});put(3,tube,{0,0,0},{1,1,1},1,{.62f,.48f,.43f,1});
 for(int i=0;i<14;i++){float z=-80+i*12.f;put(3,torus,{0,5,z},{4.8f,1.4f,4.8f},3,{.85f,.62f,.16f,1},{pi/2,0,0});for(int k=0;k<9;k++){float a=k*2*pi/9;put(3,torus,{cosf(a)*2.1f,5+sinf(a)*2.1f,z},{2.1f,.5f,2.1f},3,{.8f,.6f,.22f,1},{pi/2,0,a},3,k*.2f);}}
 // The red wooden chamber, glowing marbled discs and a floral iron rose.
 scenes[4].name="05 / the red chamber";scenes[4].fog={.065f,.012f,.008f};scenes[4].density=.018f;
 box(4,{0,-.25f,0},{16,.5f,60},10,{.38f,.2f,.12f,1});for(float x:{-8.f,8.f})box(4,{x,9,0},{.5f,18,60},10,{.36f,.16f,.1f,1});box(4,{0,18,0},{16,.5f,60},13,{1,.65f,.08f,1});
 for(int i=0;i<22;i++){float z=-27+i*2.6f;for(float x:{-7.7f,7.7f}){put(4,sphere,{x,4+(i%4)*3.4f,z},{.03f,1.0f+(i%3)*.3f,1.0f+(i%3)*.3f},13,{1,.11f,.025f,1});}if(i%3==0)box(4,{0,7.f+(i%3),z},{16,.5f,.6f},10);}
 for(int k=0;k<12;k++){float a=k*2*pi/12;put(4,torus,{cosf(a)*1.4f,9+sinf(a)*1.4f,5},{1.45f,.3f,1.45f},3,{.13f,.08f,.04f,1},{pi/2,0,a},1,k*.2f);}put(4,sphere,{0,9,5},{3,3,.08f},13,{1,.2f,.025f,1});
 box(4,{0,9,30},{16,18,.5f},10,{.36f,.16f,.1f,1});box(4,{0,9,-30},{16,18,.5f},10,{.36f,.16f,.1f,1});
 // Monument over water: four piers, tall arch ribs, patterned revolving hoops.
 scenes[6].name="07 / the product";scenes[6].fog={.17f,.075f,.075f};scenes[6].density=.005f;
 box(6,{0,-.4f,0},{400,.5f,400},14,{.17f,.4f,.45f,1});
 for(float x:{-9.f,9.f})for(float z:{-3.f,3.f}){put(6,cylinder,{x,10,z},{.3f,20,.3f},10,{.65f,.4f,.2f,1});box(6,{x,20,z},{1,.6f,1},3);}
 for(float z:{-3.f,0.f,3.f}){put(6,arch,{0,20,z},{9,14,1},9,{.8f,.8f,.64f,1});put(6,arch,{0,20,z+.3f},{9.3f,14.4f,1},3,{.45f,.48f,.45f,1});}
 for(int k=0;k<7;k++){float r=2.4f+k*.65f;put(6,torus,{0,21,0},{r,1,r},k%2?3:9,{.72f,.68f,.45f,1},{pi/2,k*.22f,k*.17f},1,k*.3f);}put(6,sphere,{0,21,0},{1,1,1},3,{.8f,.62f,.2f,1});
 scenes[7]=scenes[6];scenes[7].name="08 / end scroller";
}
XMMATRIX World::transform(const Object&o,float t)const{auto m=XMLoadFloat4x4(&o.world);if(o.motion==1)m=XMMatrixRotationRollPitchYaw(t*.07f,t*.13f,t*.045f)*m;else if(o.motion==2)m=XMMatrixRotationY(t*.11f+o.seed)*m*XMMatrixTranslation(0,sinf(t*.4f+o.seed)*.6f,0);else if(o.motion==3)m=XMMatrixRotationY(t*(int(o.seed)%2?-.3f:.3f))*m;return m;}
Camera World::camera(int s,float t)const{
 float a=t*.065f;switch(s){
 case 0:return {{.5f*sinf(t*.14f),2.4f,-74+t*3.3f},{0,3,-55+t*3.3f},1.12f};
 case 1:if(t<16)return {{sinf(t*.03f)*15,4+t*.45f,-95+t*3},{0,9,-10},1.f};return {{30*cosf((t-16)*.1f),12+3*sinf(a),-42+15*sinf((t-16)*.1f)},{0,8,-10},1.05f};
 case 2:return {{2*sinf(t*.14f),2.6f+.6f*sinf(t*.2f),-42+t*1.8f},{-2,2.3f,-28+t*1.8f},1.15f};
 case 3:return {{sinf(a)*1.3f,5+cosf(a)*1.3f,-83+t*3},{0,5,-64+t*3},1.15f};
 case 4:return {{3*sinf(t*.1f),5+3*sinf(t*.06f),-25+fmodf(t*.8f,42.f)},{0,11,-8+fmodf(t*.8f,42.f)},1.2f};
 case 5:return {{24*sinf(a-.8f),3+9*(.5f+.5f*sinf(t*.07f)),24*cosf(a-.8f)},{0,9,0},1.07f};
 default:{float radius=std::max(13.f,55-t*.85f);return {{radius*sinf(a*.7f),8+8*sinf(t*.04f),-radius*cosf(a*.7f)},{0,21,0},1.05f};}}
}
