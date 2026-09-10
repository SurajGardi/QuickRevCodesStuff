#include<iostream>
using namespace std;

class Base
{
    public:
        int i,j;
        virtual void Fun()      //1000 virtual addresses
        {
            cout<<"Base Fun\n";
        }
        virtual void Gun()      //2000
        {   
            cout<<"Base Gun\n";
        }
         void Sun()             //3000
        {
            cout<<"Base sun\n";
        }
         void Run()             //4000
        {
            cout<<"Base Run\n";
        }


};

class Derived : public Base
{
   public:
        int x,y;
        void Fun()          //5000
        {
            cout<<"Derived Fun\n";
        }

        virtual void Gun()      //6000
        {
            cout<<"Derived Gun\n";
        }
        virtual void Run()      //7000      //
        {
            cout<<"Derived Run\n";
        }
        virtual void Mun()      //8000
        {
            cout<<"Derived Mun\n";
        }
};

int main()
{

    cout<<sizeof(Base)<<"\n";   //12    //increased here due to pointer is already 4 bytrs soo its increse by 4 
    cout<<sizeof(Derived)<<"\n";  //20    // if class contains the virtual keyword then it contains n+8/4


    Base *dp = new Derived;        //Upcasting

    dp->Fun();              //Derived Fun
    dp->Run();              //Base Run

    return 0;
}