import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import java.nio.file.*;
import java.nio.charset.StandardCharsets;
public class ExportFR08 extends GhidraScript{
 public void run()throws Exception{
  Path out=Paths.get(getScriptArgs()[0]);Files.createDirectories(out);
  DecompInterface decompiler=new DecompInterface();decompiler.openProgram(currentProgram);
  FunctionIterator iterator=currentProgram.getFunctionManager().getFunctions(true);int count=0;
  while(iterator.hasNext()&&!monitor.isCancelled()){
   Function f=iterator.next();long a=f.getEntryPoint().getOffset();if(a<0x401000L||a>=0x411000L)continue;
   DecompileResults r=decompiler.decompileFunction(f,45,monitor);
   if(r.decompileCompleted()&&r.getDecompiledFunction()!=null){String text="// Original FR08 function at "+f.getEntryPoint()+"\n"+r.getDecompiledFunction().getC();Files.write(out.resolve(String.format("%08x_%s.c",a,f.getName())),text.getBytes(StandardCharsets.UTF_8));count++;}
  }
  decompiler.dispose();println("Exported "+count+" original engine functions");
 }
}
