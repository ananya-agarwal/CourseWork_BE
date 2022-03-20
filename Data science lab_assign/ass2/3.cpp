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
void mid();
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
cout<<"Wanna continue????";
cin>>ch;
cout<<endl;
}while(ch=='y' || ch=='Y');
}
void L_List::mid()
{
if(head==NULL)
cout<<"List is empty!!!\n";
else
{
node *slow=head,*fast=head;
while(fast!=NULL && fast->next!=NULL)
{
slow=slow->next;
fast=(fast->next)->next;
}
cout<<"\n middle element's data is"<<slow->data<<endl;
cout<<"middle element's address is: "<<slow<<endl;
}
}
void L_List::display()
{
if(head==NULL)
cout<<"List is empty!!!!\n";
else
{
node *temp=head;
while(temp!=NULL)
{
cout<<temp->data<<" ";
temp=temp->next;
}
cout<<"\n";
}
}
int main()
{
L_List a;
cout<<"Enter elements of Linked List \n";
a.create();
cout<<"Entered Linked List is \n";
a.display();
a.mid();
return 0;	
}
