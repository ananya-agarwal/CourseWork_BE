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
		temp=temp->next;
		cout<<' ';
		cout<<temp->data;
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
		cout<<" 4. exit \n";
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

