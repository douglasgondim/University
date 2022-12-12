
import java. util.Iterator;
import java. util.Map;
import java. util.HashMap;


public class Main {

   public static void printScope(HashMap<Symbol, HashMap<Symbol, Type>> classScope){
      if(classScope.isEmpty()) System.out.println("EMPTY SCOPE");
      if(classScope.containsKey(Symbol.symbol("BS"))) System.out.println("Contains BS");
      for (HashMap.Entry<Symbol, HashMap<Symbol, Type>> entry : classScope.entrySet()) {
         System.out.println(entry.getKey() + ":" /*entry.getValue().toString()*/);
     }

   }
   public static void main(String [] args) {
      try {
         Program root = new MyParser(System.in).Goal();
         // root.accept(new PrettyPrintVisitor());
         SymbolTableVisitor sv = new SymbolTableVisitor();
         root.accept(sv);
         printScope(sv.getclassScope());

         
      }
      catch (ParseException e) {
         System.out.println(e.toString());
      }
   }
}