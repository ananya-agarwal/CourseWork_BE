#include<iostream>
using namespace std;

int main()
{
    int a[5][5],m,n,i,j,k,l;
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
    int found=0;
    for(i=0;i<m;i++)
    {
        int flag=0;
        int min=a[i][0];
        l=0;
        for(j=1;j<n;j++)
        {
            if(a[i][j]<min)
            {
                min=a[i][j];
                l=j;
            }
        }
        for(k=0;k<m;k++)
        {
            if(a[k][l]>min)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            cout<<min<<" is the saddle point \n";
            found++;
        }
    }
    if(found==0)
    cout<<"No saddle point found! \n";
    return 0;
}
