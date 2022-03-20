#include<iostream>
using namespace std;
void binary_search(int a[],int size)
{
    int val,flag=-1;
    int start=0,end=size-1;
    int mid;
    cout<<"Enter the value to search";
	cin>>val;
    while(start<=end)
    {
        mid=(start+end)/2;
        if(a[mid]>val)
        {
            end=mid-1;
        }
        else if(a[mid]==val)
        {
            flag=mid;
            cout<<"Element found at index:"<<mid<<endl;
            break;
        }
        else
        {
            start=mid+1;
        }
    }
    if(flag==-1)
    {
        cout<<"Element not found! \n";
    }
}

int main()
{
    int i,n;
    cout<<"Enter the number of elements : ";
    cin>>n;
    int *a=new int[n];
    cout<<"Enter array elements : \n";
    for(i=0;i<n;i++)
    cin>>a[i];
    binary_search(a,n);
    delete []a;
    return 0;
}
