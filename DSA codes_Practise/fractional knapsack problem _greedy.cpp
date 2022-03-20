#include<iostream>
using namespace std;

int partition(float ratio[],int p, int r, float weight[], float value[])
{
	int x,i,j,t;
    x=ratio[r];
	i=p-1;
	for(j=p;j<=r-1;j++)
	{
		if(ratio[j]<=x)
		{
			i+=1;
			t=ratio[i];
			ratio[i]=ratio[j];
			ratio[j]=t;
			
			t=weight[i];
			weight[i]=weight[j];
			weight[j]=t;
			
			t=value[i];
			value[i]=value[j];
			value[j]=t;
			
		}
	}
	t=ratio[i+1];
	ratio[i+1]=ratio[r];
	ratio[r]=t;
	
	t=weight[i+1];
	weight[i+1]=weight[r];
	weight[r]=t;
	
	t=value[i+1];
	value[i+1]=value[r];
	value[r]=t;
	
	return i+1;
}
void quick_sort(float ratio[],int p,int r, float weight[], float value[])
{
	if(p<r)
	{
		int q=partition(ratio,p,r,weight,value);
		quick_sort(ratio,p,q-1,weight,value);
		quick_sort(ratio,q+1,r,weight,value);
	}
}


int main()
{
	int W,n;
	cout<<"\n Enter the weight/capacity of the knapsack: ";
	cin>>W;
	cout<<"\n Enter the number of objects: ";
	cin>>n;
	float weight[n],value[n],ratio[n],x[n];
    cout<<"\n Enter the value and weight of the objects respectively: ";
    for(int i=0;i<n;i++)
    {
    	x[i]=0;
    	cin>>value[i];
    	cin>>weight[i];
    	ratio[i]=value[i]/weight[i];
	}
		
	quick_sort(ratio,0,n-1,weight,value);
    
	float final_value=0,sum=0;
	
	for(int i=n-1;i>=0;i--)
	{
		if(sum <= (W-weight[i]))
		{
			sum += weight[i];
			x[i]=1;
	    	float final = value[i]*x[i];
	 		final_value += final;
		}
		else
		{
			x[i] = (W-sum)/weight[i];
			float final = value[i]*x[i];
	 		final_value += final;	
	 		break; 
		}
		
	}
	for(int i=0;i<n;i++)
	{
		cout<<endl;
		cout<<"Details of object "<<i+1<<endl;
		cout<<"X : "<<x[i]<<endl;
		cout<<"Value :"<<value[i]<<endl;
		cout<<"Weight :"<<weight[i]<<endl<<endl;
	}
	cout<<"\n Optimal solution given by the greedy approach is: "<< final_value;
}


 

