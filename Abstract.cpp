#include<iostream>
using namespace std;

class Base
{
    public:
        int i,j;

        int Addition(int no1, int no2)          //1000
        {
            return no1 + no2;
        }
        virtual int Subtraction(int no1, int no2) = 0;      //.--.
        
};

class Derived : public Base
{
    public:
        int x,y;

        int Subtraction(int no1, int no2)       //2000
        {
            return no1 - no2;
        }
        int Multiplication(int no1, int no2)    //3000
        {
            return no1 * no2;
        }
};

int main()
{

    Base *bp = NULL;
    Derived dobj;

    bp = &dobj;

    cout<<bp->Addition(10,11)<<"\n";
    cout<<bp->Subtraction(10,11)<<"\n";

    //cout<<bp->Multiplication(10,11)<<"\n";        //class "Base" has no member "Multiplication"
    //cout<<dobj.Multiplication(10,11)<<"\n";       // This works due to direct accesing via object

    return 0;
}