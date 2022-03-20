#include<iostream>
using namespace std;
void bubble_sort(int a[],int size)
{
    int i,j;
    for(i=0;i<size-1;i++)
    for(j=0;j<size-i-1;j++)
    {
        if(a[j]>a[j+1])
        {
            int t=a[j];
            a[j]=a[j+1];
            a[j+1]=t;
        }
    }
}

int main()
{
    int i,n;
    cout<<"Enter the number of elements";
    cin>>n;
    int *a=new int[n];
    cout<<"Enter array elements\n";
    for(i=0;i<n;i++)
    cin>>a[i];
    bubble_sort(a,n);
    cout<<"Sorted Array\n";
    for(i=0;i<n;i++)
    cout<<a[i]<<" ";
    delete []a;
    return 0;
}
