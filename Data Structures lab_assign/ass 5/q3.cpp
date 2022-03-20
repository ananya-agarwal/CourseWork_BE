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
 cout<<"Sorry!!! Queue is full! \n";
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
 cout<<"Sorry!!! Queue is empty! \n";
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
 cout<<"\nQueue elements are: \n";
 while(temp!=NULL)
 {
 cout<<temp->data<<" ";
 temp = temp->next;
 }
 cout<<endl;
 }
 else
 {
 cout<<"Sorry!!! Queue is empty! \n";
 }
 cout<<endl;
}
int Queue::peek()
{
 return front->data;
}
int main()
{
 Queue q1,q2,q3;
 int n,i,d;
 cout<<"Enter the even no of elements in queue: ";
 cin>>n;
 while(n%2!=0)
 {
 cout<<"Enter valid i.e. even no of elements in queue: ";
 cin>>n;
 }
 for(i=0;i<n;i++)
 {
 cout<<"Enter data: \n";
 cin>>d;
 q1.enqueue(d);
 }
 for(i=0;i<n;i++)
 {
 if(i < n/2)
 q2.enqueue(q1.peek());
 else
 q3.enqueue(q1.peek());
 q1.dequeue();
 }
 for(i=0;i<n/2;i++)
 {
 q1.enqueue(q2.peek());
 q1.enqueue(q3.peek());
 q2.dequeue();
 q3.dequeue();
 }
 q1.display();
 return 0;
}
