#include<iostream>
using namespace std;
void change(int a[], int &n)
{
	int i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		if(a[i]==a[j])
		{
			for(k=j;k<n-1;k++)
			{
			    a[k]=a[k+1];
			}
			n--;
			j--;
		}
	}
}

int main()
{
	int i,n;
	cout<<"How many elements??\n";
	cin>>n;
	cout<<"Enter array elements:\n";
	int *a=new int[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	change(a,n);
	cout<<"Array after removing duplicate elements are:\n";
	for(i=0;i<n;i++)
	cout<<a[i]<<" ";
	delete []a;
	return 0;
}
