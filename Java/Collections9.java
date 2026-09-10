import java.util.*;

class Collections9
{
    public static void main(String A[])
    {
        Vector <Double> vobj = new Vector <Double> ();

        vobj.add(11.32);
        vobj.add(21.45);
        vobj.add(51.78);
        vobj.add(101.40);
        
        System.out.println(vobj);

        vobj.remove(2);
        
        System.out.println(vobj);

        Iterator iobj = vobj.iterator();

        while(iobj.hasNext())
        {
            System.out.println(iobj.next());
        }
       
       vobj.clear();
    }
}