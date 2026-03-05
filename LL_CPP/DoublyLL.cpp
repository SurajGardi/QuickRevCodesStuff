#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node * next;
    struct node * prev;
}NODE, *PNODE, **PPNODE;

// typedef struct node NODE;
// typedef struct node* PNODE;
// typedef struct node** PPNODE;

class DoublyLL
{
    private:
        PNODE first;
        int iCount;

    public:
        DoublyLL();

        void Display();
        int Count();

        void insertFirst(int);
        void insertLast(int);
        void deleteFirst();
        void deleteLast();
        void insertAtPos(int,int);
        void deleteAtPos(int);
};

DoublyLL :: DoublyLL()
{
    cout<<"Inside Constructor"<<endl;

    this->first = nullptr;
    this->iCount = 0;
}

void DoublyLL :: Display()
{
    PNODE temp = nullptr;

    temp = first;

    cout<<"nullptr";
    while(temp != nullptr)
    {
        cout<<" <==> | "<<temp->data<<" | ";
        temp = temp->next;
    }
    cout<<"<==> nullptr";
    cout<<"\n";
}

int DoublyLL :: Count()
{
    return iCount;
}

void DoublyLL :: insertFirst(int no)
{
    PNODE newn = nullptr;

    newn = new NODE;

    newn->data = no;
    newn->next = nullptr;
    newn->prev = nullptr;

    if(first == nullptr)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }
    iCount++;
}

void DoublyLL :: insertLast(int no)
{
    PNODE newn = nullptr;
    PNODE temp = nullptr;

    newn = new NODE;

    newn->data = no;
    newn->next = nullptr;
    newn->prev = nullptr;

    if(first == nullptr)
    {
        first = newn;
    }
    else
    {
        temp = first;

        while(temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp-> next = newn;
        newn->prev = temp;
    }
    iCount++;
}

void DoublyLL :: deleteFirst()
{

    if(first == nullptr)
    {
        cout<<"LL is Empty"<<endl;
        return;
    }
    else if((first)-> next == nullptr)
    {
        delete first;
        first = nullptr;
    }
    else
    {
       first = first->next;
       delete first->prev;

       first->prev = nullptr;
    }
    iCount--;
}

void DoublyLL :: deleteLast()
{
    PNODE temp = nullptr;

    if(first == nullptr)
    {
        cout<<"LL is Empty"<<endl;
        return;
    }
    else if((first)-> next == nullptr)
    {
        delete first;
        first = nullptr;
    }
    else
    {
        temp = first;

        while(temp ->next != nullptr)
        {
            temp = temp->next;
        }

        temp->prev->next = nullptr;
        delete temp;
    }
    iCount--;
}

void DoublyLL :: insertAtPos(int no, int pos)
{
    PNODE newn = nullptr;
    PNODE temp = nullptr;

    int i = 0;

    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid position to enter node"<<endl;
        return;
    }

    if(pos == 1)
    {
        insertFirst(no);
        return;
    }
    else if(pos == iCount+1)
    {
        insertLast(no);
        return;
    }
    else
    {
        newn = new NODE;

        newn->data = no;
        newn->next = nullptr;

        temp = first;

        for(i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->prev = temp;

        newn->next->prev = newn;
        temp->next = newn;
    }
    iCount++;
}

void DoublyLL :: deleteAtPos(int pos)
{
    PNODE temp = nullptr;
    PNODE target = nullptr;

    int i = 0;

    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid position to delete node"<<endl;
        return;
    }

    if(pos == 1)
    {
        deleteFirst();
        return;
    }
    else if(pos == iCount+1)
    {
        deleteLast();
        return;
    }
    else
    {
        temp = first;

        for(i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        target = temp->next;

        temp->next = target->next;
        target->next->prev = temp;

        delete target;
    }
    iCount--;
}



int main()
{
    DoublyLL dobj;
    int totNodes = 0;
    dobj.insertFirst(51);
    dobj.insertFirst(21);
    dobj.insertFirst(11);

    dobj.insertLast(101);
    dobj.insertLast(111);
    
    // dobj.deleteFirst();
    // dobj.deleteLast();

    dobj.insertAtPos(105,5);
    dobj.deleteAtPos(5);

    dobj.Display();

    totNodes = dobj.Count();
    cout<<"Total Nodes Are : "<<totNodes<<endl;

    return 0;
}