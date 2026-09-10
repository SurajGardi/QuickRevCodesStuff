import java.util.*;

class Collections5
{
    public static void main(String A[])
    {
        ArrayList <Integer> aobj = new ArrayList <Integer> ();

        aobj.add(11);
        aobj.add(21);
        aobj.add(51);
        aobj.add(101);
        
        aobj.remove(3);

       Iterator iobj = aobj.iterator();

        System.out.println("Elements of the ArrayList are : ");
       while(iobj.hasNext())
       {
        System.out.println(iobj.next());
       }

       System.out.println(aobj.size());
    }
}