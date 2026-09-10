#include<iostream>
using namespace std;

//Casting

class Demo
{
    public:
        int i,j,k;
};

class Hello : public Demo
{
   public:
        int x,y;
};

int main()
{

    cout<<sizeof(Demo);
    cout<<sizeof(Hello);

    return 0;
}