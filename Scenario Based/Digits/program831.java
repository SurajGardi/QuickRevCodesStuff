// Neon Number [  Number ]

import java.util.*;

class program831
{
    public static void main(String A[])
    {
        Scanner sobj = new Scanner(System.in);

        int iNo = 0,iTemp = 0, iDigit = 0, iSum = 0;

        System.out.println("Enter Number : ");
        iNo = sobj.nextInt();
        
        iTemp = iNo;

        iNo = iNo * iNo;

        while(iNo != 0)
        {
            iDigit = iNo % 10;
            iSum = iSum + iDigit;
            iNo = iNo / 10;
        }

        if(iTemp == iSum)
        {
            System.out.println(iTemp+" is Neon Number");
        }
        else
        {
            System.out.println(iTemp+" is NOT Neon Number");
        }

    }
}

