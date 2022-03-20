#include<iostream>
using namespace std;
int c=0;
void merge(int A[],int beg, int mid, int end)
{
	int i=beg,j=mid+1,k=beg,b[20];
	while(i<=mid && j<=end)
	{
		if(A[i]<=A[j])
		{
			b[k]=A[i];
			i++;
		}
		else
		{
			b[k]=A[j];
			j++;
		}
		k++;
		c++;
	}
	while(j<=end)
		{
			b[k]=A[j];
			k++;
			j++;
		}
	while(i<=mid)
		{
			b[k]=A[i];
			i++;
			k++;
    	}
	for(int m=beg;m<=end;m++)
		A[m]=b[m];
}
void merge_sort(int A[],int beg,int end)
{
	if(beg<end)
	{
		int mid=(beg+end)/2;
		merge_sort(A,beg,mid);
		merge_sort(A,mid+1,end);
		merge(A,beg,mid,end);
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
	merge_sort(A,0,n-1);
	cout<<"\n Arranged elements are:";
	for(i=0;i<n;i++)
	cout<<A[i]<<" ";
	cout<<"total comparisons: "<<c;
	return 0;
}
