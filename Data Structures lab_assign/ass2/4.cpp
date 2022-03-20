#include<iostream>
using namespace std;
struct node
{
int data;
node *next;
};
class L_List
{
node *head;
public:
L_List()
{
head=NULL;
}
void create();
void reverse();
void display();
};
void L_List::create()
{
char ch;
do
{
node *temp=new node;
cout<<"Enter data : ";
cin>>temp->data;
temp->next=NULL;
if(head==NULL)
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
cout<<"Wanna continue???";
cin>>ch;
cout<<endl;
}while(ch=='y' || ch=='Y');
}
void L_List::reverse()
{
if(head==NULL)
cout<<"List is empty!!!\n";
else
{
node *after=NULL,*curr=head,*prev=NULL;
while(curr!=NULL)
{
after=curr->next;
curr->next=prev;
prev=curr;
curr=after;
}
head=prev;
}
}
void L_List::display()
{
if(head==NULL)
cout<<"list is empty!!!!\n";
else
{
node *temp=head;
while(temp!=NULL)
{
cout<<temp->data<<"   ";
temp=temp->next;
}
cout<<"\n";
}
}
int main()
{
L_List a;
cout<<"Enter elements of linked list\n";
a.create();
cout<<"Entered Linked List are\n";
a.display();
a.reverse();
cout<<"\n Reversed Linked List are \n";
a.display();
return 0;
}

