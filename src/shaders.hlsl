cbuffer Frame : register(b0) {
 row_major float4x4 viewProjection;
 float4 eyeTime;
 float4 fogDensity;
 float4 lightDirection;
 float4 screen;
};
cbuffer Object : register(b1) {
 row_major float4x4 world;
 row_major float4x4 normalWorld;
 float4 tint;
 float4 parameters;
};
Texture2D image : register(t0);
SamplerState linearClamp : register(s0);
struct Vin {float3 p:POSITION;float3 n:NORMAL;float2 uv:TEXCOORD;float4 color:COLOR;};
struct Vout {float4 p:SV_POSITION;float3 pos:TEXCOORD0;float3 n:TEXCOORD1;float2 uv:TEXCOORD2;float4 color:COLOR;};
Vout meshVS(Vin v){Vout o;float4 p=mul(float4(v.p,1),world);o.p=mul(p,viewProjection);o.pos=p.xyz;o.n=normalize(mul(v.n,(float3x3)normalWorld));o.uv=v.uv;o.color=v.color;return o;}
float hash(float2 p){return frac(sin(dot(p,float2(127.1,311.7)))*43758.5453);}
float noise(float2 p){float2 i=floor(p),f=frac(p);f=f*f*(3-2*f);return lerp(lerp(hash(i),hash(i+float2(1,0)),f.x),lerp(hash(i+float2(0,1)),hash(i+1),f.x),f.y);}
float fbm(float2 p){return noise(p)*.5+noise(p*2.03)*.25+noise(p*4.07)*.125+noise(p*8.13)*.0625;}
float brick(float2 p,out float seed){p.x+=fmod(floor(p.y),2)*.5;float2 id=floor(p),q=frac(p);seed=hash(id);float2 edge=min(q,1-q);return smoothstep(.015,.055,edge.x)*smoothstep(.025,.07,edge.y);}
float3 surface(float3 pos,float3 n,float2 uv,int m,out float relief,out float metal){
 float3 an=abs(n);float2 q=an.y>.7?pos.xz:(an.x>an.z?pos.zy:pos.xy);float rough=noise(q*35);float seed=0;relief=0;metal=0;float3 col=.4;
 if(m==0||m==1||m==2){float2 tile=q*(m==0?float2(.8,.8):(m==1?float2(.65,1.25):float2(1.2,2.4)));float mortar=brick(tile,seed);float grain=fbm(q*5);float3 base=m==0?float3(.24,.29,.31):(m==1?float3(.43,.44,.4):float3(.43,.44,.36));col=base*(.62+grain*.7+seed*.28)*lerp(.38,1,mortar);col*=.87+.2*rough;relief=(mortar*.9+rough*.16)*.018;}
 else if(m==3){float seams=step(.97,frac(q.x*.4))+step(.985,frac(q.y*.3));float rust=smoothstep(.56,.78,fbm(q*.8)+noise(q*7)*.25);col=lerp(float3(.28,.31,.29),float3(.25,.115,.035),rust)*(.8+.4*rough);col*=1-saturate(seams)*.55;metal=.78;relief=rough*.006;}
 else if(m==5){col=1;metal=0;}
 else if(m==6){float2 p=q*5;float wires=min(abs(frac(p.x+p.y)-.5),abs(frac(p.x-p.y)-.5));clip(.055-wires);col=.25;metal=.9;}
 else if(m==7){float grass=fbm(q*.7);col=lerp(float3(.12,.15,.08),float3(.29,.29,.16),grass);relief=rough*.03;}
 else if(m==8){float roof=brick(q*float2(2,4),seed);col=float3(.24,.13,.09)*(.8+seed*.4)*lerp(.5,1,roof);relief=roof*.02;}
 else if(m==10){float g=fbm(float2(q.x*4,q.y*.12))+noise(q*float2(25,.9))*.18;col=lerp(float3(.07,.025,.01),float3(.38,.16,.045),g);relief=g*.012;}
 else if(m==11){float f=fbm(q*5)+noise(q*28)*.3;clip(f-.53);col=lerp(float3(.12,.09,.015),float3(.45,.32,.06),f);}
 else if(m==12){float2 p=q*5;float2 r=frac(p)-.5;float d1=abs(r.x+r.y)*.7071,d2=abs(r.x-r.y)*.7071;float ridge=max((1-smoothstep(.02,.1,d1))*(1-smoothstep(.12,.4,abs(r.x-r.y))),(1-smoothstep(.02,.1,d2))*(1-smoothstep(.12,.4,abs(r.x+r.y))));col=float3(.27,.31,.3)*(.55+ridge*.65+rough*.15);relief=ridge*.04;metal=.8;}
 else if(m==13){float marble=sin(uv.x*45+uv.y*30+fbm(uv*8)*15);col=lerp(float3(.3,.01,0),float3(1,.68,.18),smoothstep(-.5,.7,marble));}
 else if(m==14){float waves=sin(q.x*2+eyeTime.w)*sin(q.y*1.7-eyeTime.w*.7)+noise(q*5);col=float3(.11,.31,.34)*(.5+.3*waves);metal=.7;relief=waves*.025;}
 else if(m==9){float2 p=uv*float2(18,4);float a=sin(p.x*6.283)*sin(p.y*6.283);float petal=sin((p.x+p.y)*6.283)+cos((p.x-p.y)*6.283);col=lerp(float3(.21,.13,.055),float3(.72,.73,.54),smoothstep(-.4,.3,a));col=lerp(col,float3(.38,.035,.02),smoothstep(1,1.7,petal));col*=.85+.25*noise(p*10);metal=.28;relief=a*.008;}
 return col;
}
float4 meshPS(Vout i):SV_TARGET{
 int mat=(int)parameters.x;float3 n=normalize(i.n);float relief,metal;float3 col=surface(i.pos,n,i.uv,mat,relief,metal)*tint.rgb;
 float3 dp1=ddx(i.pos),dp2=ddy(i.pos);float3 r1=cross(dp2,n),r2=cross(n,dp1);float det=dot(dp1,r1);float3 grad=(ddx(relief)*r1+ddy(relief)*r2)/(abs(det)+.00001);n=normalize(n-clamp(grad,-.6,.6));
 float3 view=normalize(eyeTime.xyz-i.pos);if(dot(n,view)<0)n=-n;
 float3 l=normalize(lightDirection.xyz);float diffuse=saturate(dot(n,l));float hemi=saturate(n.y*.5+.5);
 float spec=pow(saturate(dot(n,normalize(view+l))),lerp(12,75,metal));
 float3 ambient=lerp(float3(.10,.105,.10),float3(.32,.37,.42),hemi);
 float3 lit=col*(ambient+diffuse*float3(.95,.82,.61))+spec*float3(.52,.49,.39)*(metal+.05);
 // Repeating warm fixtures illuminate the corridor without imported lightmaps.
 float scene=screen.z;
 if(scene==0||scene==1||scene==2){float period=scene==2?6:5;float z=round(i.pos.z/period)*period;float3 lp=float3(i.pos.x<0?-3.6:3.6,5.5,z);if(scene==1)lp.x=i.pos.x<0?-7.6:7.6;
 float3 d=lp-i.pos;float dist=length(d);float attenuation=3.5/(1+dist*dist*.5);lit+=col*float3(1,.50,.17)*attenuation*(.4+.6*saturate(dot(n,normalize(d))));}
 if(mat==5)lit=tint.rgb*3.5; if(mat==13)lit=col*1.7;
 float fog=1-exp(-length(eyeTime.xyz-i.pos)*fogDensity.w);lit=lerp(lit,fogDensity.rgb,fog);
 return float4(max(lit,0),1);
}
struct Full {float4 p:SV_POSITION;float2 uv:TEXCOORD;};
Full fullVS(uint id:SV_VertexID){Full o;o.uv=float2((id<<1)&2,id&2);o.p=float4(o.uv*float2(2,-2)+float2(-1,1),1,1);return o;}
float4 skyPS(Full i):SV_TARGET{
 float2 p=i.uv;float t=eyeTime.w*.006;float2 skyUV=float2(p.x*7+t,p.y*5-t);float clouds=fbm(skyUV+float2(fbm(skyUV+3),fbm(skyUV-5))*3);clouds+=noise(skyUV*24)*.05;float3 c=lerp(fogDensity.rgb*1.8,fogDensity.rgb*.3,saturate(1-p.y));c+=float3(.17,.15,.12)*smoothstep(.32,.7,clouds);
 float sun=pow(saturate(1-length((p-float2(.72,.25))*float2(1,1.7))),24);c+=sun*float3(.8,.48,.2);return float4(c,1);
}
float4 postPS(Full i):SV_TARGET{
 float2 uv=i.uv;float2 px=1/screen.xy;float3 c=image.Sample(linearClamp,uv).rgb;
 float3 bloom=0;[unroll]for(int k=0;k<8;k++){float a=k*.785398;float2 d=float2(cos(a),sin(a));bloom+=max(image.Sample(linearClamp,uv+d*px*4).rgb-.8,0);}
 c+=bloom*.035;c=1-exp(-c*1.45);c=pow(saturate(c),1/2.2);
 float vig=pow(saturate(16*uv.x*uv.y*(1-uv.x)*(1-uv.y)),.15);c*=lerp(.6,1,vig);c+=(hash(i.p.xy+frac(eyeTime.w)*100)-.5)/255;
 float fade=parameters.x;c*=fade;return float4(c,1);
}
Vout textVS(Vin v){Vout o=(Vout)0;o.p=float4(v.p.x/screen.x*2-1,1-v.p.y/screen.y*2,0,1);o.uv=v.uv;o.color=v.color;return o;}
float4 textPS(Vout i):SV_TARGET{float a=image.Sample(linearClamp,i.uv).r;return float4(i.color.rgb,i.color.a*a);}
