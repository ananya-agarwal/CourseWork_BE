#include<iostream>
using namespace std;

struct all{
	int job;
	int profit;
	int deadline;
	int completed; //say agar ek job 4 deadline vaali array mein rkhdi pehli hi aur ab 3 rd vale ke liye voh eligible hai but repeat nahi krnge use
};

void job_seq(all obj[], int n, int max);

int partition(all A[],int p, int r) // profit ke according ascending order me laga diya
{
	int x,i,j;
	all t;
    x=A[r].profit;
	i=p-1;
	for(j=p;j<=r-1;j++)
	{
		if(A[j].profit <= x)
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
	int i,n,max;
	
	cout<<"\n Enter the total number of jobs: ";
	cin>>n;
	all obj[n];
	for(i=0;i<n;i++)
	{
	obj[i].completed=0;
	obj[i].job=i;
	cout<<"\n Enter deadline of job number "<<i+1<<": "; //spaces sirf " " ke andar vaali matter krnengi
	cin>>obj[i].deadline;
	cout<<"\n Enter profit of job number "<<i+1<<": ";
	cin>>obj[i].profit;
    }
    
    max=obj[0].deadline;
    for(i=0;i<n;i++)
    {
    	if(max<obj[i].deadline)
    	max=obj[i].deadline;
	}
	
	quick_sort(obj,0,n-1);
	
    job_seq(obj,n,max);	
    return 0;
}

void job_seq(all obj[], int n ,int max)
{
    int i,j,c=0,timeslot[max],total_profit=0; //c=0 kyuki first job ko selected nahi maan rhe hai and need c kyuki possible hai ki koi slot khaali hi reh jaaye
    cout <<"\n Following jobs are selected: "<< endl;
    for(i=max-1;i>=0;i--) //this loop if for timeslot array where we want to place the ans but from right to left
	{
		for(j=n-1;j>=0;j--)//this loop is for original array jo ki ascending order mein sorted hai thus isme sabse peeche vaale element se krna shuru krnge
		{
		  if(obj[j].deadline>=i+1 && obj[j].completed == 0)
		  {
		  	obj[j].completed=1;
		  	timeslot[i]=obj[j].profit;
		  	total_profit += obj[j].profit;
		  	c++;
		  	break;// agar uss vaale index pe element rkh diya toh uske liye searching band krdo
		  }
		
        }	
		
	} 
    cout<<"\n Total # jobs selected are: "<<c;
    cout<<"\n Selected jobs vector is: ";
    for(int i=0;i<max;i++)
    cout<<timeslot[i]<<" ";
    cout<<"\n Total profit is: "<<total_profit;
}
 
