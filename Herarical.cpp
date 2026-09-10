#include<iostream>
using namespace std;

class Base1
{
    public:
    int i,j;

    Base1()
    {
        cout<<"Base1 Constructor \n";
    }
    ~Base1()
    {
        cout<<"Base1 Distructor \n";
    }
};

class Base2
{
    public:
    int x,y;

    Base2()
    {
        cout<<"Base2 Constructor \n";
    }
    ~Base2()
    {
        cout<<"Base2 Distructor \n";
    }
};

class Derived : public Base2,Base1
{
    public:
    int a;

    Derived()
    {
        cout<<"Derived Constructor \n";
    }
    ~Derived()
    {
        cout<<"Derived Distructor \n";
    }
};


int main()
{

    Derived dobj;
    cout<<"Size of Derived is : "<<sizeof(dobj)<<"\n";

    return 0;
}