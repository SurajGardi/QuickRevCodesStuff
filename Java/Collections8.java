import java.util.*;

class Collections8
{
    public static void main(String A[])
    {
        Hashtable <String, Integer> hobj = new Hashtable <String, Integer> ();  

        hobj.put("PPA",25000);
        hobj.put("LB",26000);
        hobj.put("Python",22000);
        hobj.put("Angular",24000);
        hobj.put("LSP",30000);
        
        System.out.println(hobj);

        System.out.println(hobj.get("LB"));
        System.out.println(hobj.get("Python"));
        System.out.println(hobj.get("LSP"));

        hobj.put("Python",31000);

        System.out.println(hobj.get("Python"));

        Enumeration eobj = hobj.keys();

        while(eobj.hasMoreElements())
        {
            System.out.println(eobj.nextElement());
        }
    }
}