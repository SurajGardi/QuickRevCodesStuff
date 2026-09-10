import java.util.*;

class Collections4
{
    public static void main(String A[])
    {
        ArrayList <Integer> aobj = new ArrayList <Integer> ();

        aobj.add(11);
        aobj.add(21);
        aobj.add(51);
        aobj.add(101);
        
        System.out.println(aobj);

        aobj.add(3,41);

        System.out.println(aobj);

        if(aobj.contains(51))
        {
            System.out.println("Elements is present");
        }


        aobj.clear();

        System.out.println(aobj);
    }
}