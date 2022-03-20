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
		void i_beg();
		void create();
		void display();
		void check();
};
void l_list::i_beg()
{
	node *temp=new node;
	cout<<"Enter the value to be inserted : ";
	cin>>temp->data;
	temp->next=temp;
	if(head == NULL)
	head=temp;
	else
	{
		temp->next=head;
		node *temp1=head;
		while(temp1->next!=head)
		temp1=temp1->next;
		temp1->next=temp;
		head=temp;
	}
}
void l_list::create()
{
	int a;
	node *temp=new node;
	cout<<"Enter the value to be inserted : ";
	cin>>a;
	temp->data=a;
	temp->next=temp;
	if(head == NULL)
	head=temp;
	else
	{
		temp->next=head;
		node *temp1=head;
		while(temp1->next!=head)
		temp1=temp1->next;
		temp1->next=temp;
	}
}		
void l_list::display()
{
	if(head==NULL)
	cout<<"List is empty!!\n";
	else
	{
		cout<<"Linked list elements are \n";
		node *temp=head;
		while (temp->next!=head)
		{
			cout<<temp->data<<' ';
			temp=temp->next;
		}
		cout<<temp->data;
	}
}
void l_list::check()
{
	node *temp=head;
	while (temp->next!=NULL && temp->next!=head) 
	
	/* have checked for both the conditions since let if the linked list was circular
	 then the frst condition gets satisfied and an infinite loop will execute and thus the second condition is needed 
	 the second condition is needed because let say if right now temp->next=null then after temp=temp->next.....now in null->next == head here, there is no significance 
	 of accessing null->next thus system is crashed thus along with second condition , first condition of getting next != null is also must*/
	 
	{
		temp=temp->next;
		if(temp->next == head)
		cout<<"yes it is a singly circular linked list \n";
		else
		cout<<"not a singly circular linked list \n";
	}
}
int main()
{
	l_list a;
	char c;
	int ch;
	do
	{
		cout<<"Menu of choices :\n";
		cout<<" 1. insert at beginning \n";
		cout<<" 2. insert other than at the beginning \n";
		cout<<" 3. display \n";
		cout<<" 4. check for the existence of the singly circular linkd list \n";
		cout<<" 5. exit \n";
		cout<<" \n enter your choice : ";
		cin>>ch;
		cout<<endl;
		switch(ch)
		{
			case 1:
				a.i_beg();
				break;
			case 2:
				a.create();
				break;
			case 3:
				a.display();
				break;
			case 4:
				a.check();
				break;
			case 5:
				exit(0);
			default:
			cout<<"Invalid choice!!\n";
		}
		cout<<"\n wannna continue??";
		cin.ignore();
		cin>>c;
		system("cls");
	}
	while(c=='y'|| c=='Y');
	}
	
