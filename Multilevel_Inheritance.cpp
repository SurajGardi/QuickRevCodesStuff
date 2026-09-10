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

class Derived : public Base
{
    public:
    int p,q;

    Derived()
    {
        cout<<"Derived Constructor\n";
    }
    ~Derived()
    {
        cout<<"Derived Distructor\n";
    }
};

class DerivedX : public Derived
{
    public:
    int p,q;

    DerivedX()
    {
        cout<<"DerivedX Constructor\n";
    }
    ~DerivedX()
    {
        cout<<"DerivedX Distructor\n";
    }
};

int main()
{

    DerivedX dobj;
    cout<<"size of default is : "<<sizeof(dobj)<<"\n";
    return 0;
}