#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

int Count(PNODE first,PNODE last)
{
    int iCount = 0;

    if(first == NULL || last == NULL)
    {
        return iCount;
    }

    do
    {
        iCount++;
        first = first->next;
    }while(first != last->next);

    return iCount;
}

void InsertFirst(PPNODE first, PPNODE last, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if(*first == NULL && *last == NULL)
    {
        *first = newn;
        *last = newn;

        (*last)->next = *first;

    }
    else
    {
        newn->next = *first;
        *first = newn;

        (*last)-> next = *first;
    }
    
}

void InsertLast(PPNODE first, PPNODE last, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if(*first == NULL && *last == NULL)
    {
        *first = newn;
        *last = newn;

        (*last)->next = *first;
    }
    else
    {
        (*last)->next = newn;
        *last = newn;

        (*last)-> next = *first;
    }

}

void DeleteFirst(PPNODE first, PPNODE last)
{
    PPNODE temp = *first;

    if(*first == NULL && *last == NULL)
    {
        printf("LL is empty");
        return;
    }
    else if(*first == *last)
    {
        free(*first);
        *first = NULL;
        *last= NULL;
    }
    else
    {
        *first = (*first)->next;
        (*last)->next = *first;

        free(temp);
    }
}

void DeleteLast(PPNODE first, PPNODE last)
{
    PNODE temp = NULL;

    if(*first == NULL && *last == NULL)
    {
        printf("LL is empty");
        return;
    }
    else if(*first == *last)
    {
        free(*first);
        *first = NULL;
        *last= NULL;
    }
    else
    {
        temp = *first;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        
        free(*last);
        *last = temp;
        (*last)->next = *first;
        
    }
}

void DeleteAtPosition(PPNODE first, PPNODE last, int pos)
{
    int iCount = Count(*first, *last);
    PNODE temp = NULL;
    PNODE target = NULL;

    if(*first == NULL && *last == NULL)
    {
        return;
    }
    if(pos < 1 || pos > iCount)
    {
        printf("Invalid position");
        return;
    }

    if(pos == 1)
    {
        DeleteFirst(*first, *last);
    }
    else if(pos = iCount)
    {
        DeleteLast(*first,*last);
    }
    else
    {
        temp = *first;

        for(int i = 0; i < pos; i++)
        {
            temp= temp->next;
        }

        target = temp->next;

        temp->next = target->next;

        free(target);
    }
}





void Display(PNODE first, PNODE last)
{
    if(first == NULL || last == NULL)
    {
        return;
    }

    do
    {
        printf("| %d | ->",first->data);
        first = first->next;
    }while(first != last->next);

    printf("NULL");
}

int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;

    InsertFirst(&head,&tail,51);
    InsertFirst(&head,&tail,21);
    InsertFirst(&head,&tail,11);

    InsertLast(&head,&tail,101);


    Display(head,tail);

    return 0;
}