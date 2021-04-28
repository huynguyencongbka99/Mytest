#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct Contact
{
    char key[10];
    char name[30];
    string mail;
    string phone;
    string position;
    int birth_year;
};

struct node
{
    Contact data;
    node *prev;
    node *next;
};
node *first, *last;


void Append();
void ForwardDisplay();
void Delete();
void Insert();
void BackwardDisplay();

int main()
{
    int ch;
    //Chúng ta sẽ gán con trỏ first trong hàm main, và tất nhiên con trỏ last sẽ được gán 
    // trong lúc ta tạo được các node mới.
    first = NULL;

    do
    {
        cout<<"\n1.Append 2. Forward Display 3. Backward Display";
        cout<<"\n4. Search & delete 5. Search & insert 6. Exit \n";
        cin>>ch;
        if(ch==1) Append();
        if(ch==2) ForwardDisplay();
        if(ch==3) BackwardDisplay();
        if(ch==4) Delete();
        if(ch==5) Insert(); 
    } while (ch!=6);
    
    Contact x;
    return 0;
}


void Append()
{
    char c; //choose function
    node *p; //Allocate memory for node
    do
    {
        p = new node;
        cout<<"Key: ";cin.ignore();
        cin.getline(p->data.key,10);
        cout<<"Name: ";fflush(stdin);
        cin.getline(p->data.name,30);
        cout<<"Mail: ";fflush(stdin);
        getline(cin,p->data.mail);
        cout<<"Phone: ";fflush(stdin);
        getline(cin,p->data.phone);
        cout<<"Position: ";fflush(stdin);
        getline(cin,p->data.position);
        cout<<"Birth_year: ";
        cin>>p->data.birth_year;

        p->next = NULL; // We are appending so that p->next = NULL
        if(first == NULL)
        {
            p->prev = NULL;
            first= p;
            last = p;
        }
        else
        {
            last->next = p;
            p->prev = last;
            last = p;
        }
        cout << "\nContinue Y/N?";
        cin>>c;
    } while (c == 'Y' || c == 'y');
}

void Insert()
{
    char t[10]; //choose a key to insert
    bool found = false;
    node *p; //first
    node *q; //new_node

    cout<<"\nInput a key to insert an element before it ... :";
    cin.ignore();
    cin.getline(t,10);

    p = first;
    if(p != NULL)
    {
        while (p != NULL && found == 0)
        {
            if(strcmp(p->data.key, t) == 0) found =true;
            else p = p->next;
            //Hai dòng phía trên thể hiện rằng khi ta tìm được phần tử mà có key trùng với
            // phần tử  đang muốn truy vết thì ta sẽ chuyển con trỏ đến sau phần tử đã tìm được đó 
        
        }
    }

    if(found==1)
    {
        q=new node;
        cout<<"\nInput a new contact: ";
        cout<<"\nKey: ";cin.ignore();
        cin.getline(q->data.key,10);
        cout<<"Name: ";fflush(stdin);
        cin.getline(q->data.name,30);
        cout<<"Mail: ";fflush(stdin);
        getline(cin,q->data.mail);
        cout<<"Phone: ";fflush(stdin);
        getline(cin,q->data.phone);
        cout<<"Position: ";fflush(stdin);
        getline(cin,q->data.position);
        cout<<"Birth_year: ";
        cin>>q->data.birth_year;

        if(p==first)
        {
            q->next=p;
            q->prev=NULL;
            first->prev=q;
            first=q;
        }
        else
        {
            q->next=p;
            q->prev=p->prev;
            p->prev->next=q;
            p->prev=q;
        }
    }
    else
    {
        cout<<"\nThere is not this contact!";
    }
}

void ForwardDisplay()
{
    node *p; int no_=0;
    if(first==NULL) cout<<"\nLinked List is empty!";
    else
    {
        p=first;
        while (p!=NULL)
        {
            no_++;
            cout<<p->data.key<<", Name: "<<p->data.name<<",mail: "<<p->data.mail<<", phone: "<<p->data.phone<<", position: "
            <<p->data.position<<", birth_year: "<<p->data.birth_year<<endl;
            p=p->next;
        }    
    }
    cout<<"\n===========================\n";
}
void BackwardDisplay()
{
    node *p; int no_=0;
    if(first==NULL) cout<<"\nLinked List is empty!";
    else
    {
        p=last;
        while (p!=NULL)
        {
            no_++;
            cout<<p->data.key<<", Name: "<<p->data.name<<",mail: "<<p->data.mail<<", phone: "<<p->data.phone<<", position: "
            <<p->data.position<<", birth_year: "<<p->data.birth_year<<endl;
            p=p->prev;
        }    
    }
    cout<<"\n===========================\n";
}

void Delete()
{
    char t[10];
    bool found=false;
    node *p;
    cout<<"\nInput a key to delete ...: ";
    cin.ignore();
    cin.getline(t,10);
    if(first!=NULL)
    {
        p=first;
        while(p!=NULL && found == 0)
        {
            if(strcmp(p->data.key,t)==0) found=true;
            else p=p->next;
        }
    }
    else
    {
        cout<<"The list is empty!";
    }

    if(found==true)
    {
        if(p==first) first=first->next;
        else p->prev->next=p->next;
        if(p->next!=NULL) p->next->prev=p->prev;
        else last=p->prev;
        delete p;
    }
    else
    {
        cout<<"\nThere is not this contact!";
    }
}