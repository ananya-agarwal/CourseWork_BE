#include<iostream>
using namespace std;

struct node
{
    char data;
    node *next;
};

class stack
{
    node *top;
    public:
    stack()
    {
        top=NULL;
    }
    bool isEmpty();
    bool isFull();
    void push(char a);
    void pop();
    char peek();
    void display();
};

bool stack::isEmpty()
{
    return (top==NULL);
}

bool stack::isFull()
{
    node *temp=new node;
    if(temp==NULL)
    {
        delete temp;
        return true;
    }
    else
    {
        delete temp;
        return false;
    }
}

void stack::push(char a)
{
    if(isFull())
        cout<<"Overflow! \n";
    else
    {
        node *temp=new node;
        temp->data=a;
        temp->next=top;
        top=temp;
    }
}

void stack::pop()
{
    if(isEmpty())
        cout<<"Underflow! \n";
    else
    {
        node *temp=top;
        top=top->next;
        cout<<temp->data<<" deleted! \n";
        delete temp;
    }
}

char stack::peek()
{
    return top->data;
}

void stack::display()
{
    if(isEmpty())
        cout<<"Underflow! \n";
    else
    {
        node *temp=top;
        while(temp!=NULL)
        {
            cout<<temp->data;
            temp=temp->next;
        }
        cout<<endl;
    }
}

int main()
{
    stack s;
    int i;
    char str[20];
    cout<<"Enter a string : ";
    cin.getline(str,20);
    for(i=0;str[i]!='\0';i++)
        s.push(str[i]);
    cout<<"\nReversed string : ";
    s.display();
    return 0;
}

