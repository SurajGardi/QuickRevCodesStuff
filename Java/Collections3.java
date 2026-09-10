import java.util.*;

class Collections3
{
    public static void main(String A[])
    {
        float Arr[] = {11.89f,51.56f,21.45f,101.89f,75.34f,95.90f};

        System.out.println("Data traversal using for - each");
        for(float no : Arr)
        {
            System.out.println(no);
        }

        Arrays.sort(Arr);
        
        System.out.println("Data traversal using for - each after sorting");
        for(float no : Arr)
        {
            System.out.println(no);
        }

        int iRet = 0;
        iRet = Arrays.binarySearch(Arr,21.45f);

        System.out.println("Return value of binary search is : "+iRet);

        iRet = Arrays.binarySearch(Arr,121.78f);

        if(iRet >= 0)
        {
            System.out.println("Element is present");
        }
        else
        {
            System.out.println("There is no such element");
        }

    }
}