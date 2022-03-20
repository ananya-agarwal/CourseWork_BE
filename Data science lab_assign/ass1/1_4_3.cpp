#include<iostream>
using namespace std;
void display(int a[][5],int m,int n)
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int m,n,a[5][5],i,j;
    cout<<"Enter the number of rows";
    cin>>m;
    cout<<"Enter the number of columns";
    cin>>n;
    cout<<"Enter 2-D array elements in matrix\n";
    for(i=0;i<m;i++)
    for(j=0;j<n;j++)
    cin>>a[i][j];
    cout<<"\nEntered Matrix is\n";
    display(a,m,n);
    int b[5][5],r,c;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            b[j][i]=a[i][j];
        }
    }
    r=n;
    c=m;
    cout<<"\nTranspose of the entered matrix\n";
    display(b,r,c);
    return 0;
}
