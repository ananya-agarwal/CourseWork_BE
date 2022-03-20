#include<iostream>
using namespace std;

int main()
{
    int a[5][5],m,n,i,j,sum;
    cout<<"Enter the no of rows : ";
    cin>>m;
    cout<<"Enter the no of columns : ";
    cin>>n;
    cout<<"Enter matrix elements : \n";
    for(i=0;i<m;i++)
    for(j=0;j<n;j++)
    cin>>a[i][j];
    cout<<"Entered matrix : \n";
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        cout<<a[i][j]<<" ";
        cout<<endl;
    }
    for(i=0;i<m;i++)
    {
        sum=0;
        for(j=0;j<n;j++)
        sum+=a[i][j];
        cout<<"Sum of row "<<i<<" : "<<sum<<endl;
    }
    for(j=0;j<n;j++)
    {
        sum=0;
        for(i=0;i<m;i++)
        sum+=a[i][j];
        cout<<"Sum of column "<<i<<" : "<<sum<<endl;
    }
    return 0;
}
