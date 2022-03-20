#include<iostream>
using namespace std;
void insert(int a[],int &size,int val,int index)
{
	int i;
	for(i=size-1;i>=index;i--)
	{
		a[i+1]=a[i];
	}
	a[index]=val;
	size++;
}

int main()
{
    int i,n;
    cout<<"Enter the number of elements in array";
    cin>>n;
    int *a=new int[n];
    cout<<"Enter array elements\n";
    for(i=0;i<n;i++)
    cin>>a[i];
    cout<<endl;
    for(i=0;i<n-1;i++)
    {
        if(a[i+1]>a[i]+1)
        {
            cout<<"Missing Number is"<<a[i]+1<<endl;
            insert(a,n,a[i]+1,i+1);    
        }
    }
    cout<<endl;
    cout<<"Final array after change\n";
    for(i=0;i<n;i++)
    cout<<a[i]<<" ";
    delete []a;
    return 0;
}
