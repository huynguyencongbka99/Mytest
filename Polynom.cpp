#include<bits/stdc++.h>
using namespace std;

struct Polynom
{
    int coef;
    int exp;
    Polynom *next;
};
Polynom *Poly1, *Poly2, *PolySum;
Polynom *node, *ptr, *ptr1, *ptr2;


void PolySumOf2Polynom()
{
    node = new Polynom;
    PolySum=node;
    ptr1=Poly1;
    ptr2=Poly2;
    while (ptr1!=NULL && ptr2!=NULL)
    {
        ptr=node;
        if(ptr1->exp < ptr2->exp)
        {
            node->coef = ptr2->coef;
            node->exp=ptr2->exp;
            ptr2=ptr2->next; //update ptr list 2
        }
        else if(ptr1->exp > ptr2->exp)
        {
            node->coef = ptr1->coef;
            node->exp=ptr1->exp;
            ptr1=ptr1->next; //update ptr list 1
        }
        else
        {
            node->coef=ptr1->coef+ptr2->coef;
            node->exp=ptr2->exp;
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        node=new Polynom;
        ptr->next; //update ptr list Result
    }

    if(ptr1==NULL)
    {
        while (ptr2!=NULL)
        {
            node->coef=ptr2->coef;
            node->exp=ptr2->exp;
            ptr2=ptr2->next;    //update ptr list 2
            ptr=nodee;
            node=new Polynom;
            ptr->next=node;
        }
    }
    else if(ptr2==NULL)
    {
        while (ptr1!=NULL)
        {
            node->coef=ptr1->coef;
            node->exp=ptr1->exp;
            ptr1=ptr1->next;    //update ptr list 1
            ptr=node;
            node=new Polynom;
            ptr->next=node;
        }
    }
    ptr->next=NULL;
}

int main()
{
    PolySumOf2Polynom();
    return 0;
}