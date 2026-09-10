#include<iostream>
using namespace std;

float Area(float Rad, float PI)
{
    float Ans = 0.0f;
    Ans = PI * Rad * Rad;
    return Ans;
}
int main()
{
    float input = 0.0f;
    cout<<"Enter the radious of Circle : \n";
    cin>>input;

    float Result = Area(input,3.14f);

    cout<<"Area of Circle : \n"<< Result<<"\n";


    return 0;
}