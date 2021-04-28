#include<iostream>
using namespace std;
#define MAX 10

/*
Trong một mảng a[1...max] để chứa các phần tử  của hàng đợi. Chúng ta cần 3 biến nguyên 
front để đánh dấu phần tử đầu tiên đang là phần tử thứ mấy của màng a, biến nguyên 
back để đánh dấu phần tử cuối cùng của hàng đợi đang là phần tử thứ mấy của mảng,
biến count để đếm số phần tử đang có trong hàng đợi.
Lần đầu tiên đưa vào queue một phần tử ta xếp nó vào a[1] và cho front = 1, back =1, count =1.
Tiếp theo phần tử thứ hai được xếp vào a[2] và back = 2. Nếu tổng số phần tử của 
queue = max thì queue bị đầy, ta chỉ có thể huỷ bỏ bớt phần tử. Mỗi lần huỷ bớt phần 
tử  của queue thì biến front tăng lên 1
*/

struct queue 
{
    int a[MAX+1];
    int front;
    int back;
    int count;
};
struct queue q;

void Putq(int n);
void Display();
int Getq();


int main()
{
    int c,n;
    q.count=0;
    q.front=0;
    q.back=0;
    for(c=1;c<=MAX;c++) q.a[c]=0;
    do
    {
        cout<<"\n1. Put  2. Get  3. Display  4. Exit \n";
        cout<<"Choose (1..4) : "; cin>>c;
        if(c==1)
        {
            if(q.count==MAX)
                cout<<"\nQueue overflow, Element number = "<<q.count;
            else 
            {
                cout<<"Input n = ";cin>>n;
                Putq(n);
            }
        }
        if(c==2)
        {
            if(q.count==0) 
                cout<<"\nQueue is empty";
            else
            {
                cout<<"\nGet element = "<<Getq();
            }
        }
        if(c==3)
        {
            Display();
        }
    } while (c!=4);
    

    return 0;
}



void Putq(int n)
{
    if(q.count==0)
    {
        q.front=1;
        q.back=1;
        q.count=1;
        q.a[1]=n;
    }
    else
    {
        q.back=(q.back % MAX)+1;
        q.a[q.back]=n;
        q.count++;
    }
}
void Display()
{
        int i;
        cout<<"\nFront = "<<q.front<<", back= "<<q.back<<", count= "<<q.count<<" ";
        for(i=1;i<=MAX;i++) cout<<"\nElement "<<i<<" = "<<q.a[i];
}
int Getq()
{
    int x;
    q.count--;
    x=q.a[q.front];
    q.a[q.front]=0;
    q.front=(q.front % MAX)+1;
    if(q.count==0)
    {
        q.front=0;
        q.back=0;
    }
    return x;
}
