#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node * next;
}NODE, *PNODE, **PPNODE;

class SinglyCLL
{
    private:
        PNODE first;
        PNODE last;
        int iCount;
    
    public:
        SinglyCLL();

        void Display();
        int Count();

        void InsertFirst(int);
        void InsertLast(int);
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPosition(int,int);
        void DeleteAtPosition(int);
};

SinglyCLL :: SinglyCLL()
{
    cout<<"Inside Constructor"<<endl;

    this->first = nullptr;
    this->last = nullptr;
    this->iCount = 0;
}

void SinglyCLL :: Display()
{
    if(first == NULL && last == NULL)
    {
        return;
    }

    PNODE temp = first;

    do
    {
        cout<<" | "<<temp->data<<" | -> ";
        temp = temp->next;
    }while(temp != last->next);
    
    cout<<"\n";
}

int SinglyCLL :: Count()
{
    return iCount;
}

void SinglyCLL :: InsertFirst(int no)
{
    PNODE newn = nullptr;

    newn = new NODE;

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

        last->next = newn;
    }
    iCount++;
}

void SinglyCLL :: InsertLast(int no)
{
    PNODE newn = nullptr;

    newn = new NODE;

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
    //newn->next = first;
    }
    iCount++;
}

void SinglyCLL :: DeleteFirst()
{
    if(first == nullptr && last == nullptr)
    {
        cout<<"LL is Empty"<<endl;
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

void SinglyCLL :: DeleteLast()
{
    PNODE temp = nullptr;
    
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
        temp = first;

        while (temp->next != last)
        {
            temp = temp->next;
        }

        delete last;

        last = temp;
        temp->next = first;
        // last->next = first;
        
    }

    iCount--;
}

void SinglyCLL :: InsertAtPosition(int no, int pos)
{
    PNODE newn = nullptr;
    PNODE temp = nullptr;

    int i = 0;

    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid Position";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
        return;
    }
    else if(pos == iCount+1)
    {
        InsertLast(no);
        return;
    }
    else
    {
        newn = new NODE;

        newn->data = no;
        newn->next = nullptr;

        temp = first;

       for(i = 1; i < pos -1 ; i++)
       {
        temp = temp-> next;
       }

       newn->next = temp->next;
       temp->next = newn;
    }
    iCount++;
}

void SinglyCLL ::  DeleteAtPosition(int pos)
{
    PNODE temp = nullptr;
    PNODE target = nullptr;

    int i = 0;

    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid Position";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
        return;
    }
    else if (pos == iCount)
    {
        DeleteLast();
        return;
    }
    else
    {
        temp = first;

        for(int i = 1; i < pos - 1; i++)
        {
            temp = temp -> next;
        }
        target = temp->next;

        temp->next = target->next;
        // temp->next = temp->next->next;
        delete target;
    }
    iCount--;
}


int main()
{

    SinglyCLL sobj;
    int iRet = 0;

    sobj.InsertFirst(51);
    sobj.InsertFirst(21);
    sobj.InsertFirst(11);

    sobj.InsertLast(101);
    sobj.InsertLast(111);
    sobj.InsertLast(121);

    // sobj.DeleteFirst();

    // sobj.DeleteLast();

    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of elements are :"<<iRet<<"\n";


    sobj.InsertAtPosition(105,5);

    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of elements are :"<<iRet<<"\n";


    sobj.DeleteAtPosition(5);

    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of elements are :"<<iRet<<"\n";
    return 0;
}