#include<iostream>
using namespace std;

class Demo
{
    public:
        int i,j;
        virtual void Fun()
        {
            cout<<"Base Fun\n";
        }
};

class Hello : public Demo
{
   public:
        int x,y;
        void Fun()
        {
            cout<<"Derived Fun\n";
        }
};

int main()
{

    cout<<sizeof(Demo)<<"\n";   //12    //increased here due to pointer is already 4 bytes soo its increse by 4 
    cout<<sizeof(Hello)<<"\n";  //20    // if class contains the virtual keyword then it contains n+8/4


    Demo *dp = new Hello;        //Upcasting

    dp->Fun();        // Derived Fun => Due to virtual Fun() in Demo
}