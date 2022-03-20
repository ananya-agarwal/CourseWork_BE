#include<iostream>
using namespace std;
struct node
{
 int data;
 node *next;
};
class Queue
{
 node *front,*rear;
 public:
 Queue()
 {
 front = rear = NULL;
 }
 void enqueue(int d);
 void dequeue();
 bool isEmpty();
 bool isFull();
 void display();
 int peek();
};
void Queue::enqueue(int d)
{
 if(!isFull())
 {
 node *temp = new node;
 temp->data = d;
 temp->next = NULL;
 if(front == NULL)
 {
 front = rear = temp;
 }
 else
 {
 rear->next = temp;
 rear = temp;
 }
 }
 else
 {
 cout<<"Sorry!!! The Queue is full! \n";
 }
}
void Queue::dequeue()
{
 if(!isEmpty())
 {
 node *temp = front;
 front = front->next;
 if(front == NULL)
 {
 rear = NULL;
 }
 delete temp;
 }
 else
 {
 cout<<"Sorry!! Queue is empty! \n";
 }
}
bool Queue::isEmpty()
{
 return (front == NULL);
}
bool Queue::isFull()
{
 node *temp = new node;
 if(temp == NULL)
 {
 delete temp;
 return true;
 }
 delete temp;
 return false;
}
void Queue::display()
{
 if(!isEmpty())
 {
 node *temp = front;
 cout<<"The Queue elements are : \n";
 while(temp!=NULL)
 {
 cout<<temp->data<<" ";
 temp = temp->next;
 }
 cout<<endl;
 }
 else
 {
 cout<<"Sorry !!! Queue is empty! \n";
 }
 cout<<endl;
}
int Queue::peek()
{
 return front->data;
}
int main()
{
 Queue q;
 int ch,d;
 char c;
 do
 {
 cout<<"The menu of choices is as follows. \nKindly choose any one from it \n";
 cout<<"1) Enqueue \n";
 cout<<"2) Dequeue \n";
 cout<<"3) Display \n";
 cout<<"4) Peek \n";
 cout<<"5) Exit \n";
 cout<<"\nEnter your choice: ";
 cin>>ch;
 cout<<endl;
 switch(ch)
 {
 case 1:
 cout<<"Enter data: ";
 cin>>d;
q.enqueue(d);
 break;
 case 2:
 q.dequeue();
 break;
 case 3:
 q.display();
 break;
 case 4:
 cout<<"Element at front : "<<q.peek()<<endl;
 break;
 case 5:
 exit(0);
 default:
 cout<<"Wrong choice \n";
 }
 cout<<"\nDo you wanna continue? (y/n) : ";
 cin>>c;
 system("cls");
 }while(c == 'y' || c == 'Y');
}
