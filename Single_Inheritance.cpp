#include<iostream>
using namespace std;

class Base
{
    public:
    int i,j;

    Base()
    {
        cout<<"Base Constructor\n";
    }
};

class Derived : public Base
{
    public:
    int k;

    Default()
    {
        cout<<"Default Constructor\n";
    }
};

int main()
{

    Base bobj;
    Derived dobj;

    cout<<"Size of base is : "<<sizeof(bobj)<<"\n";

    cout<<"Size of Default is : "<<sizeof(dobj)<<"\n";
    return 0;
}