#include<iostream>
using namespace std;

//Redefination

class Demo
{
    public:
    void Fun(int i)
    { 
        cout<<"Base FUN\n";
    } 
};

class Hello : public Demo
{
    public:
    void Fun(int i,int j)
    {
        cout<<"Derived FUN\n";
    }
};

int main()
{

    Hello hobj;

    hobj.Demo::Fun(11); //it is not allowed
    hobj.Fun(11,21);

    return 0;
}