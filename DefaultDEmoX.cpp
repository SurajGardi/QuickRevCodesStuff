#include<iostream>
using namespace std;

float Area(float Rad, float PI = 3.14f)
{
    float Ans = 0.0f;
    Ans = PI * Rad * Rad;
    return Ans;
}
int main()
{
    float input = 0.0f;
    float Result = 0.0f;
    cout<<"Enter the radious of Circle : \n";
    cin>>input;

    Result = Area(input,7.10f);
    cout<<"Area of Circle : \n"<< Result<<"\n";

    Result = Area(input,3.14f);
    cout<<"Area of Circle : \n"<< Result<<"\n";

    return 0;
}