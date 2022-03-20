#include<iostream>
using namespace std;

int main()
{
    int a[10],n,i,j,r,c;
    cout<<"Enter the no of rows/columns : ";
    cin>>n;
    cout<<"Enter the diagonal elements of matrix : \n";
    for(i=0;i<n;i++)
    cin>>a[i];
    cout<<"Entered matrix : \n";
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j)
            cout<<a[i]<<" ";
            else 
            cout<<0<<" ";
        }
        cout<<endl;
    }
    return 0;
}
