#include<iostream>
using namespace std;
struct node
{
 char data;
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
 void enqueue(char d);
 void dequeue();
 bool isEmpty();
 bool isFull();
 void display();
 char peek();
};
void Queue::enqueue(char d)
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
 cout<<"Queue elements are: \n";
 while(temp!=NULL)
 {
 cout<<temp->data<<" ";
 temp = temp->next;
 }
 cout<<endl;
 }
 else
 {
 cout<<"Sorry!! Queue is empty!!! \n";
 }
 cout<<endl;
}
char Queue::peek()
{
 return front->data;
}
int main()
{
 Queue q;
 string str;
 int i;
 int freq[26] = {0};
 cout<<"Enter the string : ";
 getline(cin,str);
 for(i=0;str[i]!='\0';i++)
 {
 if(str[i]>='a' && str[i]<='z')
 {
 int flag = 0;
 q.enqueue(str[i]);
 freq[str[i] - 'a']++;
 while(!q.isEmpty())
 {
 if(freq[q.peek() - 'a'] == 1)
 {
 cout<<q.peek()<<" ";
flag = 1;
break;
 }
 q.dequeue();
 }
 if(flag == 0)
 cout<<-1<<" ";
 }
 }
 return 0;
}
