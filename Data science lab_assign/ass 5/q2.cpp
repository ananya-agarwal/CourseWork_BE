#include<iostream>
using namespace std;
const int size = 10;
class C_Queue
{
 int data[size];
 int front,rear;
 public:
 C_Queue()
 {
 front = rear = -1;
 }
 void enqueue(int d);
 void dequeue();
 bool isEmpty();
 bool isFull();
 void display();
 int peek();
};
void C_Queue::enqueue(int d)
{
 if(!isFull())
 {
 rear = (rear + 1)%size;
 data[rear] = d;
 if(front == -1)
 front = 0;
 }
 else
 cout<<"Sorry!!! Overflow!!! \n";
}
void C_Queue::dequeue()
{
 if(!isEmpty())
 {
 cout<<data[front]<<" deleted \n";
 if(front == rear)
 front = rear = -1;
 else
 front = (front + 1)%size;
 }
 else
 cout<<"Sorry!! Underflow! \n";
}
bool C_Queue::isEmpty()
{
 if(rear == -1)
 return true;
 return false;
}
bool C_Queue::isFull()
{
 if(front == (rear + 1)%size)
 return true;
 return false;
}
void C_Queue::display()
{
 if(!isEmpty())
 {
 int i;
 cout<<"Circular Queue elements are : \n";
 if(front <= rear)
 {
 for(i=front;i<=rear;i++)
 cout<<data[i]<<" ";
 }
 else
 {
 for(i=front;i<size;i++)
 cout<<data[i]<<" ";
 for(i=0;i<=rear;i++)
 cout<<data[i]<<" ";
 }
 }
 else
 cout<<" Sorry!! Underflow! \n";
}
int C_Queue::peek()
{
 if(!isEmpty())
 return data[front];
}
int main()
{
 C_Queue q;
 int ch,d;
 char c;
 do
 {
 cout<<" The menu of choices are: \n";
 cout<<"1) Enqueue \n";
 cout<<"2) Dequeue \n";
 cout<<"3) Display \n";
 cout<<"4) Peek \n";
 cout<<"5) Exit \n";
 cout<<"\nEnter your choice : ";
 cin>>ch;
 cout<<endl;
 switch(ch)
 {
 case 1:
 cout<<"Enter data : ";
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
 cout<<"\nDo you want to continue? (y/n) : ";
 cin>>c;
 system("cls");
 }while(c == 'y' || c == 'Y');
}
