#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next;
	node *prev;
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
	cout<<"Enter the value to be inserted-";
	cin>>temp->data;
	temp->next=temp->prev=NULL;
	if(head == NULL)
	head=temp;
	else
	{
	    head->prev=temp;
	    temp->next=head;
		head=temp;
	}
}
void l_list::create()
{
		int a;
		node *temp=new node;
		cout<<"Enter the value to be inserted-";
		cin>>a;
		temp->data=a;
		temp->next=temp->prev=NULL;
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
		temp->prev=temp1;
        }  
}
void l_list::display()
{
	if(head==NULL)
	cout<<"List is empty!!\n";
	else
	{
		cout<<"Linked list elements : \n";
		node *temp=head;
		while(temp!=NULL)
		{
			cout<<temp->data<<' ';
			temp=temp->next;
		}
		cout<<endl;
	}
}
void l_list::check()
{
	node *temp=head,*tail=head;
	int f=0;
	while(tail->next!=NULL)
	{
		tail=tail->next;
	}
	while (temp!= tail) // now we are at mid since we traversing through temp pointer in forward direction and by pointer tail from backward direction 
	{
	if(temp->data!=tail->data)
	 {
		f=1;
		cout<<"\n not palindrome \n";
		break;
	 }
	temp=temp->next; // after we comapre the first and the last , we move 1 towards right through temp and 1 towards left through pointer tail 
	tail=tail->prev;
    }
if (f==0)
cout<<"Yes it is a palindrome!!!!";
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
		cout<<" 2. insert at other than at beginning \n";
		cout<<" 3. display \n";
		cout<<" 4. checking for palindrome \n";
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

