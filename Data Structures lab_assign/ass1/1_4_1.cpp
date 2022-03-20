#include<iostream>
using namespace std;
void change(int a[], int n)
{
    int i,j;
    for(i=0,j=n-1;i<j;i++,j--)
    {
        int t=a[i];
        a[i]=a[j];
        a[j]=t;
    }
}
int main()
{
    int i,n;
    cout<<"Enter the number of elements:";
    cin>>n;
    int *a=new int[n];
    cout<<"Enter array elements:\n";
    for(i=0;i<n;i++)
    cin>>a[i];
    change(a,n);
    cout<<"Reversed Array : \n";
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    delete []a;
    return 0;
}
