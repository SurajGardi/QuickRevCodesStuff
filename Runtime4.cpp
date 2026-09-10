#include<iostream>
using namespace std;

//Redefination

class Demo
{
    public:
    void Fun()
    { 
        cout<<"Base FUN\n";
    } 
};

class Hello : public Demo
{
    public:
    void Fun()
    {
        cout<<"Derived FUN\n";
    }
};

int main()
{

    Hello hobj;
    hobj.Fun();
    return 0;

}