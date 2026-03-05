// Strong Number [ Factorial No ]
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

class program815
{
    public static void main(String A[])
    {
        Scanner sobj = new Scanner(System.in);

        int iNo = 0, iFact = 0, i = 0;

        System.out.println("Enter Number : ");
        iNo = sobj.nextInt();

        // 6!
        // 6 * 5 * 4 * 3 * 2 * 1

        iFact = 1;

        for(i = 1; i <= iNo; i++)
        {
            iFact = iFact * i;
        }
        System.out.println("Factorial is : "+iFact);
    }
}
