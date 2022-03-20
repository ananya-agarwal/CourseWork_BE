#include<iostream>
using namespace std;

struct all{
	int act;
	int start;
	int finish;
};

void act_sel(all obj[], int n);

int partition(all A[],int p, int r)
{
	int x,i,j;
	all t;
    x=A[r].finish;
	i=p-1;
	for(j=p;j<=r-1;j++)
	{
		if(A[j].finish<=x)
		{
			i+=1;
			t=A[i];
			A[i]=A[j];
			A[j]=t;
		}
	}
	t=A[i+1];
	A[i+1]=A[r];
	A[r]=t;
	return i+1;
}
void quick_sort(all A[],int p,int r)
{
	if(p<r)
	{
		int q=partition(A,p,r);
		quick_sort(A,p,q-1);
		quick_sort(A,q+1,r);
	}
}
 


int main()
{
	int i,n;
	
	cout<<"\n Enter the total number of activities: ";
	cin>>n;
	all obj[n];
	for(i=0;i<n;i++)
	{
	obj[i].act=i;
	cout<<"\n Enter starting time of each activity: ";
	cin>>obj[i].start;
	cout<<"\n Enter finishing time of activities: ";
	cin>>obj[i].finish;
    }
	quick_sort(obj,0,n-1);
    act_sel(obj,n);	
    return 0;
}

void act_sel(all obj[], int n)
{
    int i,j,k,m,c=1; //bcs frst actvty is already selected
    cout <<"\n Following activities are selected "<< endl;
 
    k=0;
    cout<<" "<<obj[k].act;
  
    for (m=1; m<n; m++)
    {
    		if (obj[m].start >= obj[k].finish)
       		{
       			cout <<" " << obj[m].act;
				k=m; //say agar 1 and 3 compare hogaya toh ab k=3 rkhdnege and ab m=4 and so on compare karega	
       			c++;
			}	
    }
    cout<<"\n "<<c;
}
 
