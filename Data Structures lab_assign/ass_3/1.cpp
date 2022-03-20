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
		void i_end();
		void i_after();
		void i_before();
		void d_specific();
		void display();
		void search();
};
void l_list::i_beg()
{
	int a;
	node *temp=new node;
	cout<<"Enter the value to be inserted : ";
	cin>>a;
	temp->data=a;
	temp->next=temp->prev=temp;
	if(head == NULL)
	head=temp;
	else
	{
		temp->next=head;
		temp->prev=head->prev;
		temp->prev->next=temp;
		head->prev=temp;
		head=temp;
	}
}
void l_list::i_end()
{
	int a;
	node *temp=new node;
	cout<<"Enter the value to be inserted : ";
	cin>>a;
	temp->data=a;
	temp->next=temp->prev=temp;
	if(head == NULL)
	head=temp;
	else
	{
		temp->next=head;
		temp->prev=head->prev;
		temp->prev->next=temp;
		head->prev=temp;
	}
}
void l_list::i_after()
{
	int a,x;
	cout<<"Enter the value to be inserted : \n";
	cin>>a;
	cout<<"Enter the element after which you want to insert the value \n";
	cin>>x;
	if(head!=NULL)
	{
	node *temp=head;
	while(temp->next!=head && temp->data!=x)
	temp=temp->next;
	if(temp->data==x)
	   {
		node *temp1=new node;
		temp1->data=a;
		temp1->prev=temp;
		temp1->next=temp->next;
		temp->next=temp1;
		temp1->next->prev=temp1;
	   }
    }
}
void l_list::i_before()
{
	int a,x;
	cout<<"Enter the value to be inserted : ";
	cin>>a;
	cout<<"Enter the element before which you want to insert the value : ";
	cin>>x;
	node *p;
	if(head == NULL)
	{
		cout<<"First create the list \n";
		return;
	}
	p=head;
	do
	{
		if(p->data==x)
		break;
		p=p->next;
	}while(p!=head);
	if(p==head && p->data!=x)
	{
		cout<<"item before which insertion is done is not present in the linked list :  \n";
		return;
	}
	node *temp=new node;
	temp->data=a;
	temp->prev=NULL;
	temp->next=NULL;
	node *q=p->prev;
	q->next=temp;
	temp->prev=q;
	temp->next=p;
	p->prev=temp;
	if(p==head)
	head=temp;
}
void l_list::d_specific()
{
	int x;
	cout<<"Enter the element you wanna delete \n";
	cin>>x;
	if(head!=NULL)
	{
	node *temp=head;
	while(temp->next!=head && temp->data!=x)
	temp=temp->next;
	if(temp->data!=x)
	cout<<"not found!! \n";
		else if(temp->next==temp)
		{
			head=NULL;
			delete temp;
			cout<<"......deletion will be successful \n";
		}
		else
		{
			temp->next->prev=temp->prev;
			temp->prev->next=temp->next;
			if(temp==head)
			head=head->next;
			delete temp;
		}
    }
}
void l_list::display()
{
     node *ptr;  
     ptr=head;  
    if(head == NULL)  
    {  
        cout<<"\n it is an empty list!! \n";  
    }     
    else  
    {  
        cout<<"\n the doubly circular linked list elemnts' are : \n";  
        while(ptr->next!= head)  
        {  
          
            cout<<ptr->data<<' ';  
            ptr = ptr->next;  
        }  
        cout<<ptr->data;  
    }  
}
void l_list::search()
{
	if(head==NULL)
	cout<<"List is empty!!\n";
	else
	{
		int x,c=0;
		node *temp=head;
		cout<<"Enter value of element to be searched : ";
		cin>>x;
		while(temp!=NULL && temp->data!=x)
		{
			temp=temp->next;
			c++;
		}
		if(temp==NULL)
		cout<<"Element not found!!!!\n";
		else
		{
			cout<<temp->data<<" found at position :"<<c+1<<endl;
		}
	}
}
int main()
{
	l_list a;
	char c;
	int ch;
	do
	{
		cout<<"........Menu of choices..... :\n";
		cout<<" 1. insert at beginning \n";
		cout<<" 2. insert at end \n";
		cout<<" 3. insert after a specific node \n";
		cout<<" 4. insert before a specific node \n";
		cout<<" 5. delete specific element \n";
		cout<<" 6. display the linked list \n";
		cout<<" 7. search \n";
		cout<<" 8. exit \n";
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
				a.i_after();
				break;
			case 4:
				a.i_before();
				break;
			case 5:
				a.d_specific();
				break;
			case 6:
				a.display();
				break;
			case 7:
				a.search();
				break;
			case 8:
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

