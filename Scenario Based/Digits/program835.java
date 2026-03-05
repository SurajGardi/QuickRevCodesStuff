// Sunny Number [   ]

import java.util.*;

class program835
{
    public static void main(String A[])
    {
        Scanner sobj = new Scanner(System.in);

        int iNo = 0;

        System.out.println("Enter Number : ");
        iNo = sobj.nextInt();

        iNo++;

        int ans = (int)Math.sqrt(iNo);

        if(iNo == (ans * ans))
        {
            System.out.println((iNo-1)+ " is Sunny Number");
        }
        else
        {
            System.out.println((iNo-1)+ " is NOT Sunny Number");
        }
    }
}

