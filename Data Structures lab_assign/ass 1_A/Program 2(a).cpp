#include<iostream>
using namespace std;

struct triplet
{
  int i,j,ele;  
};

triplet* input(int n,int a)
{
    int i;
     triplet *t=new triplet[a];
    for(i=0;i<a;i++)
    {
        cout<<"Enter row index : ";
        cin>>t[i].i;
        while(t[i].i>=n || t[i].i<0)
        {
            cout<<"Enter valid row index : ";
            cin>>t[i].i;
        }
        cout<<"Enter column index : ";
        cin>>t[i].j;
        while(t[i].j>=n || t[i].j<0)
        {
            cout<<"Enter valid column index : ";
            cin>>t[i].j;
        }
        cout<<"Enter element value : ";
        cin>>t[i].ele;
        while(t[i].ele==0)
        {
            cout<<"Enter valid element value : ";
            cin>>t[i].ele;
        }
    }
    return t;
}

void display(triplet *t,int n,int a)
{
    int i,j,k;
    cout<<"Entered Matrix : \n";
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            int flag=0;
            for(k=0;k<a;k++)
            {
                if(i==t[k].i && j==t[k].j)
                flag=t[k].ele;
            }
            cout<<flag<<" ";
        }
        cout<<endl;
    }
}

void displayTranspose(triplet *t,int n,int a)
{
    int i,j,k;
    cout<<"Transpose of the entered Matrix : \n";
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            int flag=0;
            for(k=0;k<a;k++)
            {
                if(i==t[k].j && j==t[k].i)
                flag=t[k].ele;
            }
            cout<<flag<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int n,a;
    cout<<"Enter 1st Matrix : \n";
    cout<<"Enter the no of rows/columns  : ";
    cin>>n;
    cout<<"Enter the non zero elements in sparse matrix : ";
    cin>>a;
    triplet *t;
    if(a<n*n)
    {
        t=input(n,a);
    }
    else 
    {
        cout<<"Invalid input!\n";
        return 0;
    }
    display(t,n,a);
    cout<<endl;
    displayTranspose(t,n,a);
    int n1,a1;
    cout<<endl;
    cout<<"Enter 2nd Matrix : \n";
    cout<<"Enter the no of rows/columns  : ";
    cin>>n1;
    cout<<"Enter the non zero elements in sparse matrix : ";
    cin>>a1;
    triplet *t1;
    if(a1<n1*n1)
    {
        t1=input(n1,a1);
    }
    else 
    {
        cout<<"Invalid input!\n";
        return 0;
    }
    display(t1,n1,a1);
    cout<<endl;
    displayTranspose(t1,n1,a1);
}
