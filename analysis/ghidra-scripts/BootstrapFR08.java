import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.SourceType;
import java.nio.file.*;
public class BootstrapFR08 extends GhidraScript {
 public void run() throws Exception {
  for(String line:Files.readAllLines(Paths.get(getScriptArgs()[0]))){
   if(line.trim().isEmpty())continue;
   Address a=toAddr(Long.parseLong(line.trim(),16));
   try {disassemble(a);Function f=getFunctionAt(a);if(f==null)f=createFunction(a,"fr08_"+line.trim());addEntryPoint(a);}catch(Exception e){println("skip "+a+": "+e.getMessage());}
  }
  rename(0x409ae3L,"Original_DemoTimeMilliseconds");rename(0x40a335L,"Original_DSoundTimeBytes");rename(0x40990eL,"Original_SynthCallback");
 }
 void rename(long address,String name)throws Exception{Function f=getFunctionAt(toAddr(address));if(f!=null)f.setName(name,SourceType.USER_DEFINED);}
}
