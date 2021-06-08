
#include<iostream>
using namespace std;

void bubbleSort(int *a, int n)
{
	for(int i = 0; i < n - 2; i++)
	{
		for(int j = 0; j < n - i - 1 ; j++)
		{
			if(a[j] > a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

int main()
{
	int a[] = {-2, -54, 2, 5, 3, 8, -32};
	int n = sizeof(a)/sizeof(int);
	cout<<"\nMang truoc khi sap xep la: \n";
	for(int i = 0; i < n; i++)
		cout<<"a["<<i<<"] = "<<a[i]<<"   ";
	cout<<"\nMang sau khi sap xep la: \n";
	bubbleSort(a,n);
		for(int i = 0; i < n; i++)
		cout<<"a["<<i<<"] = "<<a[i]<<"   ";
		
	return 0;
}
