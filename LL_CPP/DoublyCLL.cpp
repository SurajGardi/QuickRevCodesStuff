#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node * next;
    struct node * prev;
}NODE, *PNODE, **PPNODE;

class DoublyCLL
{
    private:
        PNODE first;
        PNODE last;
        int iCount;
    
    public:
        DoublyCLL();

        void Display();
        int Count();

        void InsertFirst(int);
        void InsertLast(int);
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPosition(int,int);
        void DeleteAtPosition(int);
};

DoublyCLL :: DoublyCLL()
{
    cout<<"Inside Constructor"<<endl;

    this->first = nullptr;
    this->last = nullptr;
    this->iCount = 0;
}

void DoublyCLL :: Display()
{
    if(first == NULL && last == NULL)
    {
        return;
    }

    PNODE temp = first;

    do
    {
        cout<<" <==> | "<<temp->data<<" | ";
        temp = temp->next;
    }while(temp != last->next);
    cout<<"<==> ";
    cout<<"\n";
}

int DoublyCLL :: Count()
{
    return iCount;
}

void DoublyCLL :: InsertFirst(int no)
{
    PNODE newn = nullptr;

    newn = new NODE;

    newn->data = no;
    newn->next = nullptr;
    newn->prev = nullptr;

    if(first == nullptr && last == nullptr)
    {
        first = newn;
        last = newn;

        last->next = first;
        first->prev = last;
    }
    else
    {
        newn->next = first;
        first ->prev = newn;

        first = newn;
    }
    last->next = first;
    first->prev = last;

    iCount++;
}

void DoublyCLL :: InsertLast(int no)
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
        first->prev = last;
    }
    else
    {    
        newn->prev = last;
        // newn->next = first;
        last->next = newn;

        last = newn;
    }
    last->next = first;
    first->prev = last;

    iCount++;
}   

void DoublyCLL :: DeleteFirst()
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
        delete first->prev;

        last -> next = first;
        first -> prev = last;
    }

    iCount--;
}

void DoublyCLL :: DeleteLast()
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
        last = last->prev;
        delete last->next;

        last->next = first;
        first->prev = last; 
    }

    iCount--;
}

void DoublyCLL :: InsertAtPosition(int no, int pos)
{
    PNODE newn = nullptr;
    PNODE temp = nullptr;

    int i = 0;

    if(pos < 1 || pos > iCount+1)
    {
        cout<<"Invalid Position";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
        return;
    }
    else if(pos == iCount)
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
       newn->prev = temp;

       temp->next = newn;
       newn->next->prev = newn;
    }
    iCount++;
}

void DoublyCLL ::  DeleteAtPosition(int pos)
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
        // target = temp->next;

        // temp->next = target->next;
        // target->next->prev = temp;

        // without using target..

        temp->next = temp->next->next;
        
        delete temp->next->prev;

        temp->next->prev = temp;

        delete target;
    }
    iCount--;
}


int main()
{

    DoublyCLL sobj;
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