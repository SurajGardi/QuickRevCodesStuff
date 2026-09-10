#include<iostream>
using namespace std;

class Hello
{
    public:
        void Display();
};

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

        friend void Hello :: Display();
};

    void Hello:: Display()
    {
        Demo obj;
        cout<<obj.i<<"\n";
        cout<<obj.j<<"\n";
        cout<<obj.k<<"\n";
    }

int main()
{

    Hello obj;
    obj.Display();
    
    return 0;

}