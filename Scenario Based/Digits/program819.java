/*
========================================================
🔢 CONCEPT: Strong Number

📌 Concept Definition:
A Strong Number is a number in which the sum of the 
factorials of its digits is equal to the original number.

Mathematically:
If N = sum of (factorial of each digit of N)
Then N is a Strong Number.

📌 Examples of Strong Numbers:
1 → 1! = 1
2 → 2! = 2
145 → 1! + 4! + 5!
     = 1 + 24 + 120
     = 145  ✅ Strong Number

📌 Core Logic:
1) Store original number in temp variable.
2) Extract last digit using (number % 10).
3) Find factorial of that digit.
4) Add factorial to sum.
5) Remove last digit using (number / 10).
6) Repeat until number becomes 0.
7) Compare sum with original number.

📌 Optimization Used:
Instead of calculating factorial every time using loop,
we pre-store factorial values of digits 0–9 in an array.

Index → Digit
Value → Factorial of digit

Example:
FactArr[4] = 24
FactArr[5] = 120

This reduces Time Complexity and avoids repeated calculation.

📌 Time Complexity:
O(d) → where d = number of digits

📌 Space Complexity:
O(1) → Only fixed array of size 10

========================================================
*/
import java.util.*;

class program819
{
    public static boolean CheckStrong(int iNo)
    {
        int iTemp = 0, iSum = 0, iDigit = 0;

        iTemp = iNo;

        //               0  1  2  3  4    5    6     7     8      9
        int FactArr[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };       // change

        while(iNo != 0)
        {
            iDigit = iNo % 10;
            
            iSum = iSum + FactArr[iDigit];      // change

            iNo = iNo / 10;
        }

        return (iSum == iTemp); 
    }

    public static void main(String A[])
    {
        Scanner sobj = new Scanner(System.in);

        int iNo = 0;
        boolean bRet = false;
        
        System.out.println("Enter Number : ");
        iNo = sobj.nextInt();

        bRet = CheckStrong(iNo);

        if(bRet)   
        {
            System.out.println(iNo+" is a Strong Number");
        }
        else
        {
            System.out.println(iNo+" is Not a Strong Number");
        }
        
        sobj.close();
    }
}

// we can still handel by if else by chcking if sum is > than the actual no
/*
while(iNo != 0)
{
    iDigit = iNo % 10;
    iSum = iSum + FactArr[iDigit];

    if(iSum > iTemp)    // Early break optimization
    {
        break;
    }

    iNo = iNo / 10;
}

*/