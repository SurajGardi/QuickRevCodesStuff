#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}NODE, *PNODE, **PPNODE;

class SinglyLL
{
    private:
        PNODE first;
        int iCount;
    public:
        SinglyLL();

        void Display();
        void Count();

        void insertFirst(int);
        void insertLast(int);
        void deleteFirst(int);
        void deleteLast(int);

        void insertAtPos(int, int);
        void deleteAtPos(int);

};

SinglyLL :: SinglyLL()
{
    cout<<"Inside Constructor\n";
    this->first = nullptr;
    this->iCount = 0;
}

void SinglyLL :: Display()
{
    PNODE temp = first;

    while(temp != nullptr)
    {
        cout<<" | "<<temp->data<<" | ";
        temp = temp->next;
    }
    cout<<"\n";
}

int SinglyLL :: Count()
{
    PNODE temp = first;
    int cnt = 0;

    while(temp != nullptr)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

void SinglyLL :: insertFirst()
{
    PNODE newn = nullptr;

    newn = new NODE;

    newn->next = nullptr;
    newn->data = no;

    if(first == nullptr)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    iCount++;
}

void SinglyLL :: insertLast()
{
    PNODE newn = nullptr;
    PNODE temp = nullptr;

    newn = new NODE;

    newn->next = nullptr;
    newn->data = no;

    if(first == nullptr)
    {
        first = newn;
    }
    else
    {
        temp = first;

        while(temp != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

void SinglyLL :: deleteFirst()
{
    PNODE temp = nullptr;

    if(first == nullptr)
    {
        cout<<"Empty LL";
        return;
    }
    else if(first->next == nullptr)
    {
        delete first->next;
        first = nullptr;
    }
    else
    {
        temp = first;

        first = first->next;
        delete temp;
    }
    iCount--;
}

void SinglyLL :: deleteLast()
{
    PNODE temp = nullptr;

    if(first == nullptr)
    {
        cout<<"LL empty";
        return;
    }
    else if(first->next == nullptr)
    {
        delete first->next;
        first = nullptr;
    }
}

