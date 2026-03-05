// ArmStrong Number [ Merging codes ]

import java.util.*;

class program823
{
    public static void main(String A[])
    {
        Scanner sobj = new Scanner(System.in);

        int iNo = 0;

        System.out.println("Enter Number : ");

        iNo = sobj.nextInt();

        int iCount = 0, iDigit = 0, iTemp = 0, iSum = 0, iPow = 0, iCountTemp = 0;

        iTemp = iNo;
        iCountTemp = iCount;

        // count number of digits
        while(iNo != 0)
        {
            iDigit = iNo % 10;
            iCount++;
            iNo = iNo / 10;
        }

        iNo = iTemp;    // reset iNo to its OG value

        // y = iCount -> 3
        // x = iDigit 
        while(iNo != 0)
        {
            iDigit = iNo % 10;

            iPow = 1;       // reset

            // Count Power
            while(iCount != 0)
            {
                iPow = iPow * iDigit;
                iCount--;
            }

            iCount = iCountTemp;    // reset

            iSum = iSum + iPow;
            iNo = iNo / 10;
        }

        if(iSum == iTemp)
        {
            System.out.println(iTemp +" is a Armstrog Number");
        }
        else
        {
            System.out.println(iTemp +" is NOT a Armstrog Number");
        }
        
    }
}


//error