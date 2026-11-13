cbuffer State:register(b0){row_major float4x4 worldView;row_major float4x4 projection;row_major float4x4 texture0;row_major float4x4 texture1;uint4 flags;uint4 sampling;}
Texture2D t0:register(t0);Texture2D t1:register(t1);
SamplerState wrapLinear:register(s0);SamplerState clampLinear:register(s1);SamplerState wrapPoint:register(s2);SamplerState clampPoint:register(s3);
struct In{float3 p:POSITION;float3 n:NORMAL;float4 color:COLOR;float2 uv:TEXCOORD0;float2 uv1:TEXCOORD1;};
struct Out{float4 p:SV_POSITION;float4 color:COLOR;float2 uv:TEXCOORD0;float2 uv1:TEXCOORD1;};
Out vsMain(In i){Out o;float4 p=mul(float4(i.p,1),worldView);o.p=mul(p,projection);o.color=i.color.bgra;o.uv=i.uv;
 float3 r=reflect(normalize(p.xyz),normalize(mul(i.n,(float3x3)worldView)));float4 q=(flags.y&0xffff0000)==0x30000?float4(r,1):float4((flags.y&0xffff)==1?i.uv1:i.uv,0,1);o.uv1=mul(q,texture1).xy;return o;}
[maxvertexcount(3)] void gsMain(triangle Out input[3],inout TriangleStream<Out> stream){for(uint j=0;j<3;j++){Out o=input[j];if(sampling.z&1)o.uv.x-=floor(o.uv.x-input[0].uv.x+.5);if(sampling.z&2)o.uv.y-=floor(o.uv.y-input[0].uv.y+.5);o.uv=mul(float4(o.uv,0,1),texture0).xy;stream.Append(o);}}
float4 sample0(float2 uv,uint mode){if(mode==0)return t0.Sample(wrapLinear,uv);if(mode==1)return t0.Sample(clampLinear,uv);if(mode==2)return t0.Sample(wrapPoint,uv);return t0.Sample(clampPoint,uv);}
float4 sample1(float2 uv,uint mode){if(mode==0)return t1.Sample(wrapLinear,uv);if(mode==1)return t1.Sample(clampLinear,uv);if(mode==2)return t1.Sample(wrapPoint,uv);return t1.Sample(clampPoint,uv);}
float4 psMain(Out i):SV_TARGET{float4 c=sample0(i.uv,sampling.x)*i.color;float4 b=sample1(i.uv1,sampling.y);if(flags.x==7)c.rgb=saturate(c.rgb+b.rgb-.5);else if(flags.x==4)c.rgb*=b.rgb;else if(flags.x==2)c.rgb=b.rgb;else if(flags.x==8)c.rgb+=b.rgb;
 if(flags.z!=0)clip(c.a-flags.w/255.0-0.000001);return c;}
