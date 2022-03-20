#include<iostream>
using namespace std;
int b_search(int A[],int beg,int end,int key)
{
	int mid;
	while(beg<=end)
	{
		mid=(beg+end)/2;
		if(key==A[mid])
		return mid;
		if(key<A[mid])
		{
			end=mid-1;
		}
		else
		{
			beg=mid+1;
		}
	}
	return -1;
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
int k=b_search(A,0,n-1,j);
if(k==-1)
cout<<"\n element you were searching is not found!";
else
cout<<"\n element found at index "<<k<<"\n";
}
