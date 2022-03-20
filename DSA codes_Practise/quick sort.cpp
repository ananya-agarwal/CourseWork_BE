#include<iostream>
using namespace std;
int c=0;
int partition(int A[],int p, int r)
{
	int x,i,j,t,z;
    x=A[r];
	i=p-1;
	for(j=p;j<=r-1;j++)
	{
		if(A[j]<=x)
		{
			i+=1;
			t=A[i];
			A[i]=A[j];
			A[j]=t;
		}
		c++;
	}
	t=A[i+1];
	A[i+1]=A[r];
	A[r]=t;
	return i+1;
}
void quick_sort(int A[],int p,int r)
{
	if(p<r)
	{
		int q=partition(A,p,r);
		quick_sort(A,p,q-1);
		quick_sort(A,q+1,r);
	}
}
int main()
	{
	int n,i,A[20];
	cout<<"\n enter size of array: ";
	cin>>n;
	cout<<"\n enter elements in array: ";
	for(i=0;i<n;i++)
	{
		cin>>A[i];
	}
	quick_sort(A,0,n-1);
	cout<<"\n Arranged elements are:";
	for(i=0;i<n;i++)
	cout<<A[i]<<" ";
	cout<<"Total comparisons: "<<c;
	return 0;
}
