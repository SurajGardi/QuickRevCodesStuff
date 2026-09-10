#include<iostream>
using namespace std;


int main()
{
   char ch = 'A';
   int i = 11;

   char *cp = (char *)&i;  //upcasting
   int * ip = (int *)& ch;  //downcasting

    return 0;
}