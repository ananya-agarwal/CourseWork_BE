#include<iostream>
using namespace std;

int main()
{
    int n,size,i,j,k=0;
    cout<<"Enter the no of rows/columns : ";
    cin>>n;
    size=(n*(n+1))/2;
    int *a=new int[size];
    cout<<"Enter the tri-diagonal elements : \n";
    for(i=0;i<size;i++)
    cin>>a[i];
    cout<<"Entered Matrix : \n";
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i>=j)
            {
                cout<<a[k]<<" ";
                k++;
            }
            else
            {
                cout<<0<<" ";
            }
        }
        cout<<endl;
    }
}
