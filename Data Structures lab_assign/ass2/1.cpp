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
		void i_end();
		void i_before();
		void i_after();
		void d_beg();
		void d_end();
		void d_specific();
		void search();
		void display();
};
void l_list::i_beg()
{
	node *temp=new node;
	cout<<"Enter the value to be inserted";
	cin>>temp->data;
	temp->next=NULL;
	if(head == NULL)
	head=temp;
	else
	{
		node *temp1=head;
		while(temp1->next!=NULL)
		temp1=temp1->next;
		temp1->next=temp;
	}
}
void l_list::i_end()
{
node *temp=new node;
cout<<"Enter the value to insert : ";
cin>>temp->data;
temp->next=NULL;
if(head==NULL)
head=temp;
else
{
node *temp1=head;
while(temp1->next!=NULL)
temp1=temp1->next;
temp1->next=temp;
}
}
void l_list::i_before()
{
	if(head==NULL)
	{
		cout<<"list is empty!!!!\n";
	}
	else
	{
		int x;
		node *temp=new node;
		cout<<"Enter the value to be inserted:";
		cin>>temp->data;
		temp->next=NULL;
		cout<<"Enter the value before which the element should be inserted";
		cin>>x;
		node *temp1=head,*temp2=NULL;
		while(temp1!=NULL && temp1->data!=x)
		{
			temp2=temp1;
			temp1=temp1->next;
		}
		if(temp1==NULL)
		{
			cout<<"not found int he list!! \n";
			delete temp;
		}
		else if(temp1 ==head)
		{
			temp->next=head;
			head=temp;
		}
		else
		{
			temp->next=temp1;
			temp2->next=temp;
		}
	}
}
void l_list::i_after()
{
	if(head == NULL)
	{
		cout<<"List is empty !!!!!\n";
	}
	else
	{
		int x;
		node *temp=new node;
		cout<<"Enter the value to be inserted";
		cin>>temp->data;
		temp->next=NULL;
		cout<<"Enter the value before which the element should be inserted";
		cin>>x;
		node *temp1=head;
		while(temp1!=NULL && temp1->data!=x)
		temp1=temp1->next;
		if(temp1==NULL)
		{
			cout<<"Element not found!!!\n ";
			delete temp;
		}
		else
		{
			temp->next=temp1->next;
			temp1->next=temp;
		}
	}
}
void l_list::d_beg()
{
	if(head==NULL)
	cout<<"List is empty!!\n";
	else
	{
		node *temp=head;
		head=head->next;
		delete temp;
	}
}
void l_list::d_end()
{
	if(head==NULL)
	cout<<"List is empty!!\n";
	else
{
node *temp=head,*temp1=NULL;
while(temp->next!=NULL)
{
	temp1=temp;
	temp=temp->next;
	}	
	if(temp==head)
	head=NULL;
	else
	temp1->next=NULL;
	delete temp;
}
}
void l_list::d_specific()
{
	if(head==NULL)
	cout<<"List is empty!!!\n";
	else
	{
		int x;
		cout<<"Enter the value of element to be deleted";
		cin>>x;
		node *temp=head,*temp1=NULL;
		while(temp!=NULL && temp->data!=x)
		{
			temp1=temp;
			temp=temp->next;
		}
		if(temp==NULL)
		cout<<"Element not found!!\n";
		else if(temp==head)
		{
			head=head->next;
			delete temp;
		}
		else
		{
			temp1->next=temp->next;
			delete temp;
		}
	}
}
void l_list::search()
{
	if(head==NULL)
	cout<<"List is empty!!\n";
	else
	{
		int x,count=0;
		node *temp=head;
		cout<<"Enter value of element to be searched";
		cin>>x;
		while(temp!=NULL && temp->data!=x)
		{
			temp=temp->next;
			count++;
		}
		if(temp==NULL)
		cout<<"Element not found!!\n";
		else
		{
			cout<<temp->data<<"found at position :"<<count<<endl;
		}
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
		while (temp!=NULL)
		{
			cout<<temp->data<<' ';
			temp=temp->next;
		}
		cout<<endl;
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
		cout<<" 2. insert at end \n";
		cout<<" 3. insert before specific node \n";
		cout<<" 4. insert after specific node \n";
		cout<<" 5. delete from beginning \n";
		cout<<" 6. delete from end \n";
		cout<<" 7. delete specific element \n";
		cout<<" 8. search \n";
		cout<<" 9. display \n";
		cout<<" 10. exit \n";
		cout<<" \n enter your choice : ";
		cin>>ch;
		cout<<endl;
		switch(ch)
		{
			case 1:
				a.i_beg();
				break;
			case 2:
				a.i_end();
				break;
			case 3:
				a.i_before();
				break;
			case 4:
				a.i_after();
				break;
			case 5:
				a.d_beg();
				break;
			case 6:
				a.d_end();
				break;
			case 7:
				a.d_specific();
				break;
			case 8:
				a.search();
				break;
			case 9:
				a.display();
				break;
			case 10:
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

