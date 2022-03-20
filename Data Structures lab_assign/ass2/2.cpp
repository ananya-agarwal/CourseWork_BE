#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};
class l_list
{
	node *head;
	public:
	l_list()
	{
		head=NULL;
	}
	void create();
	void count_delete(int x);
	void display();
};
void l_list::create()
{
	char ch;
	do
	{
		node *temp=new node;
		cout<<"Enter the data\n";
		cin>>temp->data;
		temp->next=NULL;
		if(head == NULL)
		{
			head=temp;
		}
		else
		{
			node *temp1=head;
			while(temp1->next!=NULL)
			temp1=temp1->next;
			temp1->next=temp;
		}
		cout<<"wanna continue??";
		cin>>ch;
		cout<<endl;
		}while(ch=='y' || ch=='Y');
	}
void l_list::count_delete(int x)
{
	if(head==NULL)
	cout<<"linked list is empty!!!\n";
	else
	{
		int f=0;
		node *temp=head,*pre=head;
		while(temp!=NULL)
		{
			if(temp->data==x)
			{
				
				f++;
				node *temp1=temp;
				if(temp==head)
				head=head->next;
				else
				pre->next=temp->next;
				temp=temp->next;
				delete temp1;
			}
			else
			{
				pre=temp;
				temp=temp->next;
			}
		}
		cout<<"\n no of occurences of"<<x<<":"<<f<<"\n";
	}
}
void l_list::display()
{
	if(head == NULL)
	cout<<"List is empty !!\n";
	else
	{
		node *temp=head;
		while(temp!=NULL)
		{
			cout<<temp->data<<"";
			temp=temp->next;
		}
		cout<<"\n";
	}
}
int main()
{
	int x;
	l_list a;
	cout<<"enter elements\n";
	a.create();
	cout<<"Entered linked list\n";
	a.display();
	cout<<"\n enter the value of element to be first counted and then deleted ";
	cin>>x;
	a.count_delete(x);
	cout<<"\n resulting linked list\n";
	a.display();
}
