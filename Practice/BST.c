#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// MACROs

#define Max(a,b) (((a) > (b)) ? (a) : (b))

struct node 
{
    int data;
    struct node *lchild;
    struct node *rchild;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void Insert(PPNODE first, int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn =(PNODE) malloc(sizeof(NODE));

    newn->data = no;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if(*first == NULL)  // BST is Empty
    {
        *first = newn;
    }
    else        // BST contain atleast 1 element
    {
        temp = *first;

        while(1)        // executes till break
        {
            if(no == (temp->data))
            {
                printf("Duplicate Element : Unable to insert node \n");
                free(newn);
                break;
            }
            else if(no > (temp->data))      // rchild
            {
                if(temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    break;
                }
                temp = temp->rchild;        // for traversal in right side of tree
            }
            else if(no < (temp->data))      // lchild
            {
                if(temp->lchild == NULL)
                {
                    temp->lchild = newn;
                    break;
                }
                temp = temp->lchild;        // for traversal in left side of tree
            }
        }
    }
}

// Display Functions
void Preorder(PNODE first)
{
    if(first != NULL)
    {
        printf("%d\t",first->data);
        Preorder(first->lchild);
        Preorder(first->rchild);
    }
}

void Inorder(PNODE first)
{
    if(first != NULL)
    {
        Inorder(first->lchild);
        printf("%d\t",first->data);
        Inorder(first->rchild);
    }
}

void Postorder(PNODE first)
{
    if(first != NULL)
    {
        Postorder(first->lchild);
        Postorder(first->rchild);
        printf("%d\t",first->data);
    }
}

// Searching

bool Search(PNODE first, int no)
{
    bool bFlag = false;
    int TimeComplexity = 0;


    while(first != NULL)
    {
        if(no == first->data)
        {
            bFlag = true;
            break;
        }
        else if(no > first->data)
        {
            first = first->rchild;
        }
        else
        {
            first = first->lchild;
        }
        TimeComplexity++;
    }

    printf("Time complexity of search is : %d\n",TimeComplexity);

    return bFlag;
}

int Count(PNODE first)
{
    static int iCount = 0;

    if(first != NULL)
    {
        iCount++;
        Count(first->rchild);
        Count(first->lchild);
    }
    return iCount;
}

int CountLeafNodes(PNODE first)
{
    static int iCount = 0;

    if(first != NULL)
    {
        if(first->rchild == NULL && first->lchild == NULL)
        {
            iCount++;
        }
        
        CountLeafNodes(first->rchild);
        CountLeafNodes(first->lchild);
    }
    return iCount;
}

int CountParentNodes(PNODE first)
{
    static int iCount = 0;

    if(first != NULL)
    {
        if(first->rchild != NULL || first->lchild != NULL)
        {
            iCount++;
        }
        
        CountParentNodes(first->rchild);
        CountParentNodes(first->lchild);
    }
    return iCount;
}

int Height(PNODE first)
{
    int leftHeight = 0;
    int rightHeight = 0;

    if(first == NULL)
    {
        return 0;   //empty tree has height 0
    }
    else
    {
        leftHeight = Height(first->lchild);
        rightHeight = Height(first->rchild);

        if(leftHeight > rightHeight)
        {
            return leftHeight + 1;
        }
        else
        {
            return rightHeight + 1;
        }
    }
}

int HeightUpdatedWithMacro(PNODE first)
{
    int leftHeight = 0;
    int rightHeight = 0;

    if(first == NULL)
    {
        return 0;   //empty tree has height 0
    }
    else
    {
        leftHeight = Height(first->lchild);
        rightHeight = Height(first->rchild);

    }
    return Max(leftHeight,rightHeight) + 1;
}


int SumOfNodes(PNODE first)
{

    int leftSum = 0, rightSum = 0;

    if(first == NULL)
    {
        return 0;
    }

    leftSum = SumOfNodes(first->lchild);
    rightSum = SumOfNodes(first->rchild);

    return (leftSum + rightSum + first->data);
}

int main()
{
    PNODE head = NULL;

    int iRet = 0;
    bool bRet = false;

    Insert(&head,11);
    Insert(&head,9);
    Insert(&head,17);
    Insert(&head,25);
    Insert(&head,7);
    Insert(&head,35);
    Insert(&head,10);
    Insert(&head,15);
    Insert(&head,21);
    Insert(&head,26);
    Insert(&head,37);
    Insert(&head,89);
    Insert(&head,91);
    Insert(&head,65);
    Insert(&head,12);
    Insert(&head,20);
    Insert(&head,44);
    Insert(&head,66);
    Insert(&head,90);
    Insert(&head,88);

    // Insert(&head,11);
    // Insert(&head,17);
    // Insert(&head,9);
    // Insert(&head,25);
    // Insert(&head,7);
    // Insert(&head,35);
    // Insert(&head,10);
    // Insert(&head,15);
    // Insert(&head,21);
    
    bRet = Search(head,66);
    if(bRet == true)
    {
        printf("Element is present\n");
    }
    else
    {
        printf("There is no such element\n");
    }

    iRet = Count(head);
    printf("Number of nodes are : %d\n",iRet);

    iRet = CountLeafNodes(head);
    printf("Number of leaf nodes are : %d\n",iRet);

    iRet = CountParentNodes(head);
    printf("Number of parent nodes are : %d\n",iRet);

    iRet = Height(head);
    printf("Height of tree is : %d\n", iRet);

    iRet = HeightUpdatedWithMacro(head);
    printf("Height of tree is with Macro: %d\n", iRet);

    iRet = SumOfNodes(head);
    printf("Sum of all tree nodes are : %d\n", iRet);

    return 0;
}