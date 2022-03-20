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
    int m,n,a[5][5],i,j,k;
    int p,q,b[5][5],c[5][5];
    cout<<"Enter the number of rows in matrix 1";
    cin>>m;
    cout<<"Enter the number of columns in matrix 1";
    cin>>n;
    cout<<"Enter elements of 1st matrix\n";
    for(i=0;i<m;i++)
    for(j=0;j<n;j++)
    cin>>a[i][j];
    cout<<"\nEntered Matrix:\n";
    display(a,m,n);
    cout<<"Enter the number of rows in 2nd matrix:";
    cin>>p;
    cout<<"Enter the number of columns in 2nd matrix:";
    cin>>q;
    cout<<"Enter elements of matrix 1:\n";
    for(i=0;i<p;i++)
    for(j=0;j<q;j++)
    cin>>b[i][j];
    cout<<"\nEntered Matrix is \n";
    display(b,p,q);
    if(n==p)
    {
        for(i=0;i<m;i++)
        {
            for(j=0;j<q;j++)
            {
                c[i][j]=0;
                for(k=0;k<n;k++)
                {
                    c[i][j]+=(a[i][k]*b[k][j]);
                }
            }
        }
        cout<<"Cross Product : \n";
        display(c,m,q);
    }
    else
    {
        cout<<"Matrix multiplication not possible! \n";
    }
    return 0;
}
