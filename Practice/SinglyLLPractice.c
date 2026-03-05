#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
}NODE, *PNODE, **PPNODE;

// typedef struct node NODE;
// typedef struct node * PNODE;
// typedef struct node ** PPNODE;

void InsertFirst(PPNODE first, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data= no;
    newn->next= NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        newn->next = *first;
        *first = newn;
    }
}

void InsertLast(PPNODE first, int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        temp = *first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

void DeleteFirst(PPNODE first)
{
    PNODE temp = NULL;

    if(*first == NULL)
    {
        return;
    }
    else if((*first) ->next == NULL)
    {
        free(*first);
    }
    else
    {
        temp = *first;
        *first = temp -> next;
        free(temp);
    }
}

void DeleteLast(PPNODE first)
{
    PNODE temp = NULL;
    
    if(*first == NULL)
    {
        return;
    }
    else if((*first)->next == NULL)
    {
        free(*first);
        *first= NULL;
    }
    else
    {
        temp = *first;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        free(temp->next);
        temp->next = NULL;
    }
}

void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("| %d | ->",first->data);
        first = first->next;
    }
    printf("NULL\n");
}

int Count(PNODE first)
{
    int iCount = 0;

    while(first != NULL)
    {
        iCount++;
        first = first -> next;
    }
    return iCount;
}

void InsertAtPosition(PPNODE first,int no, int pos)
{
    int iCount = 0, i = 0;

    PNODE newn = NULL;
    PNODE temp = NULL;

    iCount = Count(*first);

    if(pos < 1 || pos > iCount+1)
    {
        printf("Invalid Position\n");
        return;
    }

    if(pos == 1)
    {
        InsertFirst(first,no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(first,no);
    }
    else
    {
        temp = *first;

        for(i = 0; i <= pos-1; i++)
        {
            temp = temp ->next;
        }

        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = no;
        newn->next =NULL;

        newn->next = temp->next;
        temp->next = newn;

    }
}

void DeleteAtPosition(PPNODE first, int pos)
{
    int iCount = 0, i = 0;

    PNODE temp = NULL;
    PNODE target = NULL;

    iCount = Count(*first);

    if(pos < 1 || pos > iCount+1)
    {
        printf("Invalid Position\n");
        return;
    }

    if(pos == 1)
    {
        DeleteFirst(first);
    }
    else if(pos == iCount+1)
    {
        DeleteLast(first);
    }
    else
    {
        temp = *first;

        for(i = 0; i <= pos-1; i++)
        {
            temp = temp ->next;
        }



        target = temp->next;
        temp->next = target->next;
        free(target);

    }
}

int main()
{
    PNODE head = NULL;
    int iRet = 0;

    InsertFirst(&head,51);
    InsertFirst(&head,21);
    InsertFirst(&head,11);

    Display(head);

    iRet = Count(head);

    printf("Number of Elements are : %d\n",iRet);

    InsertLast(&head,101);
    InsertLast(&head,111);
    InsertLast(&head,121);
    InsertLast(&head,151);

    Display(head);

    iRet = Count(head);

    printf("Number of Elements are : %d\n",iRet);

    InsertAtPosition(&head,105,5);

    Display(head);

    iRet = Count(head);

    printf("Number of Elements are : %d\n",iRet);

    DeleteAtPosition(&head,5);

    Display(head);

    iRet = Count(head);

    printf("Number of Elements are : %d\n",iRet);

    return 0;
}