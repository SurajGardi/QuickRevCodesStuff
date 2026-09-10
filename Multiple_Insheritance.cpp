#include<iostream>
using namespace std;

class Base
{
    public:
    int x,y;

    Base()
    {
        cout<<"Base Constructor\n";
    }
    ~Base()
    {
        cout<<"Base Distructor\n";
    }
};

class Derived1 : public Base
{
    public:
    int p,q;

    Derived1()
    {
        cout<<"Derived1 Constructor\n";
    }
    ~Derived1()
    {
        cout<<"Derived1 Distructor\n";
    }
};

class Derived2 : public Base
{
    public:
    int q;

    Derived2()
    {
        cout<<"Derived2 Constructor\n";
    }
    ~Derived2()
    {
        cout<<"Derived2 Distructor\n";
    }
};

int main()
{

    Derived2 dobj;
    cout<<"size of default is : "<<sizeof(dobj)<<"\n";
    return 0;
}