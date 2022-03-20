#include<iostream>
using namespace std;

int main()
{
    int a[5][5],m,n,i,j,k;
    cout<<"Enter the no of rows : ";
    cin>>m;
    cout<<"Enter the no of columns : ";
    cin>>n;
    cout<<"Enter matrix elements : \n";
    for(i=0;i<m;i++)
    for(j=0;j<n;j++)
    cin>>a[i][j];
    cout<<endl;
    cout<<"Entered Matrix : \n";
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        cout<<a[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    i=0;
    while(i<m-1)
    {
        k=i;
        for(j=i;j<n-i;j++)
        cout<<a[k][j]<<" ";
        j--;
        for(k=i+1;k<m-i;k++)
        cout<<a[k][j]<<" ";
        k--;
        j--;
        for(;j>=i;j--)
        cout<<a[k][j]<<" ";
        j++;
        k--;
        for(;k>i;k--)
        cout<<a[k][j]<<" ";
        i++;
    }
}
