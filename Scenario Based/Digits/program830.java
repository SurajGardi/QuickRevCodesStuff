// Palindrome Number [ Reverse Number ]

import java.util.*;

class program830
{
    public static void main(String A[])
    {
        Scanner sobj = new Scanner(System.in);

        int iNo = 0, iDigit = 0, iTemp = 0, iRev = 0;

        System.out.println("Enter Number : ");
        iNo = sobj.nextInt();
        
        iTemp = iNo;

        while(iNo != 0)
        {
            iDigit = iNo % 10;

            iRev = iRev * 10 + iDigit;

            iNo = iNo / 10;
        }

        if(iTemp == iRev)
        {
            System.out.println(iTemp+" is Palindrome Number");
        }
        else
        {
            System.out.println(iTemp+" is NOT Palindrome Number");    
        }

    }
}


