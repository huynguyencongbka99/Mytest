#include<stdio.h>
#include<stdlib.h>

// Declare a Stack node
struct StackNode
{
    float item;
    StackNode *next;
};


struct Stack
{
    StackNode *top;
};

Stack *StackConstruct();
void StackDestroy(Stack *s);
int StackEmpty(const Stack *s);
int StackFull(const Stack *s);
int StackPush(Stack *s, float *item);
float StackPop(Stack *s);

// function pointer
Stack *StackConstruct()
{
    Stack *s;
    s=(Stack *)malloc(sizeof(Stack));
    if(s==NULL)
    {
        return NULL;//no memory
    }
    s->top=NULL;
    return s;
}

void StackDestroy(Stack *s)
{
    while (! StackEmpty(s))
    {
        StackPop(s);
    }
    free(s);
}

int StackEmpty(const Stack *s)
{
    return (s->top == NULL);
}

int StackFull()
{
    printf("\nNO MEMORY! STACK IS FULL");
    system("pause");
    return 1;
}

int StackPush(Stack *s, float item)
{
    StackNode *node;
    node = (StackNode *)malloc(sizeof(StackNode));
    if(node == NULL)
    {
        StackFull(); return 1;
    }
    node->item=item;
    node->next=s->top;
    s->top=node;
    return 0;
}

float StackPop(Stack *s)
{
    float item;
    StackNode *node;
    if(StackEmpty(s))
    {
        return -100000;
    }
    node=s->top;
    item=node->item;
    s->top=node->next;
    free(node);
    return item; //return the value that I want to pop
}

void disp(Stack *s)
{
    StackNode *node;//node dong vai tro nhu cur
    int ct=0;float m;
    printf("\n\nDANH SACH CAC PHAN TU CUA STACK \n\n");
    if(StackEmpty(s))
    {
        printf("EMPTY STACK!");
    }
    else
    {
        node = s->top;
        do
        {
            m=node->item;
            printf("%8.3f ",m);ct++;
            if(ct % 9 == 0) printf("\n");
            node=node->next;
        } while (!(node==NULL));
        printf("\n");
        
    }
}

int main()
{
    int ch, n,i;
    float m;
    Stack *stackPtr;
    while (1)
    {
        printf("\n=========================\n");
        printf("CHUONG TRINH THU STACK\n");
        printf("\n=========================\n");
        printf("1. Create\n 2. Push\n 3. Pop\n 4. Display\n 5. Exit\n");
        printf("-------------------------------\n");
        printf("Chon chuc nang: ");
        scanf("%d",&ch);
        printf("\n\n");
        switch (ch)
        {
        case 1:
            printf("Da khoi tao STACK");
            stackPtr = StackConstruct();
            break;
        case 2:
            printf("Vao gia tri phan tu: ");
            scanf("%f",&m);
            printf("Gia tri cua phan tu vua nhap vao: %8.3f \n",m);
            StackPush(stackPtr,m);
            break;
        case 3:
            m=StackPop(stackPtr);
            if(m!=-100000)
            {
                printf("\nGia tri cua phan tu lay ra: %8.3f\n",m);
                system("pause");
            }
            else
            {
                printf("\nEmpty Stack, can't pop\n");
                break;
            }
        case 4:
            disp(stackPtr);
            break;

        case 5:
            printf("\nBye! Bye! \n");
            exit(0);
            break;
        default:
            printf("\nWrong choice");
            break;
        }
    }
    
    return 0;
}