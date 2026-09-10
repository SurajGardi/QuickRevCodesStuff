import java.util.*;

class Collections1
{
    public static void main(String A[])
    {
        int Arr[] = {11,51,21,101,75,95};

        System.out.println(Arr);

        for(int i = 0; i < Arr.length; i++)
        {
            System.out.println(Arr[i]);
        }

        System.out.println("Data traversal using for - each");
        for(int no : Arr)
        {
            System.out.println(no);
        }
    }
}