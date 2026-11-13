import struct, json, hashlib
from pathlib import Path
from PIL import Image
root=Path(__file__).parent/'runtime'
out=Path(__file__).parent/'extracted-textures'
out.mkdir(exist_ok=True)
b=(root/'trace.d8').read_bytes(); p=0; textures=[]
while p+8<=len(b):
 op,n=struct.unpack_from('<II',b,p); p+=8
 if p+n>len(b):break
 if op==1:
  uid,w,h,levels,fmt,bpp=struct.unpack_from('<6I',b,p)
  raw=root/f'texture-{uid:04d}-00.bin'
  if raw.exists():
   pixels=raw.read_bytes()
   if bpp==4 and len(pixels)==w*h*4:
    image=Image.frombytes('RGBA',(w,h),pixels,'raw','BGRA')
    if fmt==22:image.putalpha(255)
    image.save(out/f'texture-{uid:04d}.png')
    textures.append(dict(id=uid,width=w,height=h,levels=levels,format=fmt,bytes=len(pixels),sha256=hashlib.sha256(pixels).hexdigest()))
 p+=n
(out/'manifest.json').write_text(json.dumps(dict(source_exe_sha256=hashlib.sha256((root/'fr08v101.exe').read_bytes()).hexdigest(),source='Original x86 D3D8 CreateTexture/LockRect/UnlockRect, not video frames',textures=textures),indent=2),encoding='utf8')
print(f'Decoded {len(textures)} original texture images')
