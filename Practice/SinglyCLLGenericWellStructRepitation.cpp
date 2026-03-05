#include <iostream>
using namespace std;

template <class T>
struct SinglyCLLnode
{
    T data;
    SinglyCLLnode<T>* next;
};

template <class T>
class SinglyCLL
{
private:

    using NODE  = SinglyCLLnode<T>;
    using PNODE = SinglyCLLnode<T>*;

    PNODE first;
    PNODE last;
    int iCount;

public:

    SinglyCLL()
    {
        cout<<"Inside Constructor of SinglyCLL\n";
        first = nullptr;
        last = nullptr;
        iCount = 0;
    }

    void InsertFirst(T no)
    {
        PNODE newn = new NODE;
        newn->data = no;
        newn->next = nullptr;

        if(first == nullptr && last == nullptr)
        {
            first = newn;
            last = newn;
            last->next = first;
        }
        else
        {
            newn->next = first;
            first = newn;
            last->next = first;
        }

        iCount++;
    }

    void InsertLast(T no)
    {
        PNODE newn = new NODE;
        newn->data = no;
        newn->next = nullptr;

        if(first == nullptr && last == nullptr)
        {
            first = newn;
            last = newn;
            last->next = first;
        }
        else
        {
            last->next = newn;
            last = newn;
            last->next = first;
        }

        iCount++;
    }

    void DeleteFirst()
    {
        if(first == nullptr && last == nullptr)
        {
            return;
        }
        else if(first == last)
        {
            delete first;
            first = nullptr;
            last = nullptr;
        }
        else
        {
            first = first->next;
            delete last->next;
            last->next = first;
        }
        iCount--;
    }

    void DeleteLast()
    {
        if(first == nullptr && last == nullptr)
        {
            return;
        }
        else if(first == last)
        {
            delete first;
            first = nullptr;
            last = nullptr;
        }
        else
        {
            PNODE temp = first;

            while(temp->next != last)
            {
                temp = temp->next;
            }

            delete last;
            last = temp;
            last->next = first;
        }

        iCount--;
    }

    void Display()
    {
        if(first == nullptr && last == nullptr)
        {
            return;
        }

        PNODE temp = first;

        do
        {
            cout<<"| "<<temp->data<<" | -> ";
            temp = temp->next;
        } while(temp != last->next);

        cout<<"\n";
    }

    int Count()
    {
        return iCount;
    }
};


int main()
{
    
    SinglyCLL<int> sobj;
    int iRet = 0;

    sobj.InsertFirst(51);
    sobj.InsertFirst(21);
    sobj.InsertFirst(11);

    sobj.InsertLast(101);
    sobj.InsertLast(111);
    sobj.InsertLast(121);

    //sobj.InsertAtPos(105,5);

    sobj.Display();
    iRet = sobj.Count();

    cout<<"Number of elements are :"<<iRet<<"\n";

    sobj.DeleteFirst();

    sobj.Display();
    iRet = sobj.Count();

    cout<<"Number of elements are :"<<iRet<<"\n";
    
    sobj.DeleteLast();

    sobj.Display();
    iRet = sobj.Count();

    cout<<"Number of elements are :"<<iRet<<"\n";

    return 0;
}