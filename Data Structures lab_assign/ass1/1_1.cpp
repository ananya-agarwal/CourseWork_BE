#include<iostream>
using namespace std;

void create(int a[],int &size)
{
	int i,n;
	cout<<"enter the no of elements";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"Enter values in elements";
		cin>>a[i];
		size++;
	}
}

void insert(int a[],int &size)
{
	int i,val,index;
	cout<<"Enter value of element to be inserted";
	cin>>val;
	cout<<"Enter the index at which the element should be inserted:";
	cin>>index;
	while(index<0 || index>size)
	{
	    cout<<"Enter a valid index!";
	    cin>>index;
	}
	for(i=size-1;i>=index;i--)
	{
		a[i+1]=a[i];
	}
	a[index]=val;
	size++;
}

void delete_e(int a[],int &size)
{
	int i,val,f=-1;
	cout<<"Enter the value of element to be deleted";
	cin>>val;
	for(i=0;i<size;i++)
	{
		if(a[i]==val)
		{
			f=i;
			break;
		}
	}
	if(f==-1)
	{
		cout<<"Element not found!\n";
	}
	else
	{
		for(i=f;i<=size;i++)
		{
			a[i]=a[i+1];
		}
		size--;
	}
}

void search(int a[],int size)
{
	int i,val,f=-1;
	cout<<"Enter the value to search";
	cin>>val;
	for(i=0;i<size;i++)
	{
		if(a[i]==val)
		{
			f=i;
			break;
		}
	}
	if(f==-1)
	{
		cout<<"Element not found!\n";
	}
	else
	{
		cout<<"Element found at index:"<<f<<endl;
	}
}

void display(int a[],int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		cout<<a[i]<<" ";
	}
}

int main()
{
	int a[10],ch,size;
	char c;
	while(1) 
	{
		cout<<"Menu\n";
		cout<<"1) Create \n";
		cout<<"2) Display \n";
		cout<<"3) Insert \n";
		cout<<"4) Delete \n";
		cout<<"5) Search \n";
		cout<<"6) Exit \n";
		cout<<"Enter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				create(a,size);
				break;
			case 2:
				display(a,size);
				break;
			case 3:
				insert(a,size);
				break;
			case 4:
				delete_e(a,size);
				break;
			case 5:
				search(a,size);
				break;
			case 6:
				exit(0);
			default:
				cout<<"Invalid Choice! \n";
		}
		cout<<endl;
	}
}
