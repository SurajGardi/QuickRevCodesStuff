#include<iostream>
using namespace std;

class Demo
{
    public:
        int i;
    private:
        int j;
    protected:
        int k;
    
    public:
        Demo()
        {
            i = 10;
            j = 20;
            k = 30;
        }

        friend void Display();
};

void Display()
{
    Demo dobj;

    cout<<dobj.i<<"\n";
    cout<<dobj.j<<"\n";
    cout<<dobj.k<<"\n";
}

int main()
{
    Display();

    return 0;
}