/*
Bài này chúng ta sẽ làm việc với bảng băm mở.
Chương trình sử dụng hàm băm đơn giản sau
Giả sử khóa phần tử là số nguyên x, khi đó giá trị cỉa hàm băm h(x) được tính bằng 
phần dư của phép chia x cho n (h(x) = x mod n). Như vậy hàm băm là một ánh xa từ tập 
hợp các khóa vào tập số nguyên {0, 1, 2, ... , n - 1}, khóa cũng có thể là xâu ký tự
*/

/* Tất cả những gì mày đang được hưởng là tốt nhất có thể rồi
Thành công hay không chỉ là do maỳ chọn có hay không*/

#include<bits/stdc++.h>

const int n = 13;
struct phtu
{
    int khoa;
    struct phtu *next;
};
typedef struct phtu phantu;

phantu *t[n];
inline int h(int x){ return (x % n);}

void printDictionary(void)
{
    int i; phantu *p;
    for(i = 0; i < n ; i++)
    {
        p = t[i]; printf("\nLop %d: ",i);
        if(p == NULL) printf("NULL");
        while(p != NULL)
        {
            printf("%d - ", p->khoa);
            p = p->next;
        }
    }
}
int search(int x)
{
    phantu *p; int thay;
    p = t[h(x)]; thay = 0;
    while(p != NULL and !thay)
    {
        if(p->khoa == x) thay = 1; 
        else p = p->next;
    }
    return thay;
}
void insert(int x)
{
    int i;
    phantu *p;
    if(!search(x))
    {
        i = h(x);
        p = (phantu *)malloc(sizeof(phantu));
        p->khoa = x;
        p->next = t[i];
        t[i] = p;
    }
    else
    {
        printf("%d da co trong tu dien",x);
        return;
    }
}
void delete_(int x)
{
    int i, thay;
    phantu *p, *q;
    i = h(x);
    if(t[i] != NULL)
    {
        if(t[i]->khoa == x) t[i] = t[i]->next;
        else 
        {
            q = t[i];
            p = q->next;
            thay = 0;
            while(p != NULL && !thay)
            {
                if(p->khoa == x)
                {
                    thay = 1;
                    q->next = p->next;
                    free(p);
                }
                else
                {
                    q = p;
                    p = q->next;
                }
            }
            if(!thay) printf("%d khong co trong tu dien",x);
        }   
    }
}
int main()
{
    int i, chon, x;
    for(i = 0; i <n; i++) t[i] = NULL;
    do
    {
        printf("\n1. Chen  2. Xoa  3. Tim  4. In  5. Thoat  - Chon: ");scanf("%d",&chon);
        if(chon == 1)
        {
            printf("Vao phan tu moi x = ");scanf("%d", &x);
            insert(x);
        }
        if(chon == 2)
        {
            printf("Vao phan tu moi can xoa x = ");scanf("%d", &x);
            delete_(x);
        }
        if(chon == 3)
        {
            printf("Vao phan tu can tim x = ");scanf("%d", &x);
            if(search(x)) printf("%d co trong tu dien",x);
            else printf("%d khong co trong tu dien",x);
        }
        if(chon == 4) printDictionary();
    }while(chon >= 1 && chon <= 4);
    return 0;
}