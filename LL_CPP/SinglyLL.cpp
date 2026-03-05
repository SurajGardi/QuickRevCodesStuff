#include<iostream>
#include<unordered_map>
using namespace std;

typedef struct node
{
    int data;
    struct node* next;
}NODE, *PNODE, **PPNODE;


class SinglyLL
{
    private:
        PNODE first;
        int iCount;

    public:
        SinglyLL();

        void Display();
        int Count();

        void insertFirst(int);
        void insertLast(int);
        void deleteFirst();
        void deleteLast();
        void insertAtPosition(int, int);
        void deleteAtPosition(int);

        int MiddleElement(); 
        int MiddleElementX(); 

        bool CheckLoop();

        bool CheckLoopX();
        PNODE GetFirst();

        void DisplayReverseRecurssive();

};


SinglyLL :: SinglyLL()
{
    cout<<"Inside Constructor"<<endl;
    this->first = nullptr;
    this->iCount = 0;
}

void SinglyLL :: Display()
{
    PNODE temp = first;

    while(temp != nullptr)
    {
        cout<<" | "<<temp->data<<" | -> ";
        temp = temp->next;
    }
    cout<<"\n";
}

int SinglyLL :: Count()
{
    return iCount;
}

void SinglyLL :: insertFirst(int no)
{
    PNODE newn = nullptr;

    newn = new NODE;

    newn->data = no;
    newn->next = nullptr;

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

void SinglyLL :: insertLast(int no)
{
    PNODE newn = nullptr;
    PNODE temp = nullptr;

    newn = new NODE;

    newn->data = no;
    newn->next = nullptr;

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

        temp->next = newn;
    }
    iCount++;
}

void SinglyLL :: deleteFirst()
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
        return;
    }
    else if(first -> next == nullptr)          
    {
        delete first;
        first = nullptr;
    }
    else                             
    {
        temp = first;

        while(temp -> next -> next != nullptr)
        {
            temp = temp -> next;
        }

        delete temp -> next;
        temp->next = nullptr;
    }

    iCount--;
}

void SinglyLL :: insertAtPosition(int no, int pos)
{
    PNODE newn = nullptr;
    PNODE temp = nullptr;

    //int cnt = Count();

    int i = 0;

    if(pos < 1 || pos > iCount+1)
    {
        cout<<"Invalid Position";
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

       for(i = 1; i < pos -1 ; i++)
       {
        temp = temp-> next;
       }

       newn->next = temp->next;
       temp->next = newn;
       
       iCount++;
    }
}

void SinglyLL ::  deleteAtPosition(int pos)
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
        deleteFirst();
        return;
    }
    else if (pos == iCount)
    {
        deleteLast();
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
        
        iCount--;
    }
}

int SinglyLL :: MiddleElement() // TC = O(N + N/2)   SC = O(1)
{
    PNODE temp = nullptr;

    int iCnt = 0;
    int middle = 0;
    int i = 0;

    temp = first;

    if(first == nullptr)            // O(N)
    {
        cout<<"Linked List is Empty"<<endl;;
        return -1;
    }

    if(first->next == nullptr)
    {
        return first->data;
    }

    while(temp != nullptr)          // O(N/2)
    {
        temp = temp->next;
        iCnt++;
    }

    middle = (iCnt / 2) + 1;

    //temp = first;

    for(i = 1; i < middle; i++)
    {
        // temp = temp->next;
        first = first->next;
    }
    
    // return temp->data;
    return first->data;
}

int SinglyLL :: MiddleElementX()    // TC = O(N/2)   SC = O(1)
{
    PNODE teacher = nullptr;
    PNODE student = nullptr;

    if(first == nullptr)
    {
        cout<<"Linked List is Empty"<<endl;
        return -1;
    }
    else
    {
        teacher = first;
        student = first;

        //        for Even                    for Odd no LL 
        while((teacher != nullptr) && (teacher->next != nullptr))
        {
            student = student->next;
            teacher = teacher->next->next;
        }
        return student->data;
    }
}

////////// CHECK LOOP

// map stores elements in sorted order and takes log N time and uses Red-Black Tree as Data Structure, 
// while unordered_map doesn’t maintain order but gives constant
// time access on average and takes N timeTable as a Data Structure.

bool SinglyLL :: CheckLoop()    // unordered_map => TC = O(N log N)   SC = O(N)
{                               // map => TC = O(N)   SC = O(N)
    if(first == nullptr)
    {
        return false;
    }
    
    //map<PNODE, bool> visited;         // TC = O(N)   SC = O(N)
    unordered_map<PNODE, bool> visited; // TC = O(N log N)   SC = O(N)

    PNODE temp = first;

    while(temp != nullptr)
    {
        if(visited[temp] == true) // unordered_map => checking in map -> O(log N)
        {
            return true;
        }
        visited[temp] = true;   // unordered_map => inserting in map -> O(log N)
        temp = temp->next;
    }
    return false;
}

bool SinglyLL :: CheckLoopX()    // TC = O(N)   SC = O(1)
{
    PNODE slow = nullptr;
    PNODE fast = nullptr;
    
    bool bFlag = false;

    slow = first;
    fast = first;

    while((fast != nullptr) && (fast->next != nullptr))
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
        {
            bFlag = true;
            break;
        }
    }
    return bFlag;
}

PNODE SinglyLL :: GetFirst()
{
    return first;
}


// int main()
// {
//     SinglyLL sobj;

//     int totNodes = 0;
//     int iRet = 0;
//     bool bRet = false;

//     sobj.insertFirst(51);
//     sobj.insertFirst(21);
//     sobj.insertFirst(11);

//     sobj.insertLast(101);
//     sobj.insertLast(111);

//     // sobj.deleteFirst();
//     // sobj.deleteLast();
//     totNodes = sobj.Count();
//     cout<<"Total Nodes Are : "<<totNodes<<endl;

//     // sobj.insertAtPosition(105, 5);

//     sobj.Display();

//     totNodes = sobj.Count();
//     cout<<"Total Nodes Are : "<<totNodes<<endl;

//     // sobj.deleteAtPosition(6);

//     // sobj.Display();

//     // totNodes = sobj.Count();
//     // cout<<"Total Nodes Are : "<<totNodes<<endl;

//     iRet = sobj.MiddleElementX();

//     cout<<"Middle element is : "<<iRet<<endl;

//     bRet = sobj.CheckLoop();

//     if(bRet == true)
//     {
//         cout<<"There is a LOOP in Linked List"<<endl;
//     }
//     else
//     {
//         cout<<"There is NO LOOP in Linked List"<<endl;
//     }

//     return 0;
// }


// for checkLoop

int main()
{
    SinglyLL sobj;
    PNODE head = nullptr;
    PNODE temp = nullptr;
    PNODE last = nullptr;

    sobj.insertFirst(51);
    sobj.insertFirst(21);
    sobj.insertFirst(11);

    sobj.insertLast(101);
    sobj.insertLast(111);
    sobj.insertLast(121);

    // get head (like C code)
    head = sobj.GetFirst();

    // last = head->next->next->next->next->next;
    last = head;
    while(last->next != nullptr)
    {
        last = last->next;
    }

    // temp = head->next->next;
    temp = head->next->next;

    // create loop
    last->next = temp;

    if(sobj.CheckLoop())
    {
        cout<<"There is a LOOP in Linked List"<<endl;
    }
    else
    {
        cout<<"There is NO LOOP in Linked List"<<endl;
    }

    return 0;
}

