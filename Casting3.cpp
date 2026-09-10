#include<iostream>
using namespace std;

//Casting

class Demo
{
    public:
        int i,j,k;
};

class Hello : public Demo
{
   public:
        int x,y;
};

int main()
{
    Demo *dp = new Hello;        //Upcasting

    Hello *hp = new Demo;      //Downcasting NOT ALLOWED

    return 0;
}