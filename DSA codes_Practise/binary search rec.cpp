#include<iostream>
using namespace std;
int rec(int A[],int beg, int end, int key)
{
	int mid;
	if(beg==end)
	{
		if(A[beg]==key)
		{
			return beg;
		}
		else
		{
		return -1;
		}
	}
else
{
	mid=(beg+end)/2;
	if(key<A[mid])
	{
		return rec(A,beg,mid-1,key);
	}
	else
	if (key == A[mid])
	return mid;
	else
	{
		return rec(A,mid+1,end,key);
	}
}
}
int main()
{
int n,i,A[20],j;
cout<<"\n enter size of array: ";
cin>>n;
cout<<"\n enter elements in array: ";
for(i=0;i<n;i++)
{
	cin>>A[i];
}
cout<<"\n enter element you wanna search: ";
cin>>j;	
int k=rec(A,0,n-1,j);
if(k==-1)
cout<<"\n element you were searching is not found!";
else
cout<<"\n element found at index "<<k<<"\n";
}
