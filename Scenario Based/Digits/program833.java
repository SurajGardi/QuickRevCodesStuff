// Spy Number [   ]

import java.util.*;

class program833
{
    public static void main(String A[])
    {
        Scanner sobj = new Scanner(System.in);

        int iNo = 0, iSum = 0, iDigit = 0, iMult = 0, iTemp = 0;

        System.out.println("Enter Number : ");
        iNo = sobj.nextInt();

        iTemp = iNo;
        
        iMult = 1;

        while(iNo != 0)
        {
            iDigit = iNo % 10;

            iSum = iSum + iDigit;
            iMult = iMult * iDigit;

            iNo = iNo / 10;
        }
        
        if(iSum == iMult)
        {
            System.out.println(iTemp+ " is Spy Number");
        }
        else
        {
            System.out.println(iTemp+ " is NOT Spy Number");
        }
    }
}

