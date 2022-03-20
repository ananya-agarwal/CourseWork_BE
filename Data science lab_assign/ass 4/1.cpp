#include<iostream>
using namespace std;

struct node
{
    int data;
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
    void push(int a);
    void pop();
    int peek();
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

void stack::push(int a)
{
    if(isFull())
        cout<<"Stack is full.....Overflow condition!!!\n";
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

int stack::peek()
{
    return top->data;
}

void stack::display()
{
    if(isEmpty())
        cout<<"Underflow! \n";
    else
    {
        cout<<"Stack elements are as follows : \n";
        node *temp=top;
        while(temp!=NULL)
        {
            cout<<temp->data<<endl;
            temp=temp->next;
        }
        cout<<endl;
    }
}

int main()
{
    stack s;
    int ch;
    char c;
    do
    {
        cout<<"Menu of choices : \n";
        cout<<"1) Push \n";
        cout<<"2) Pop \n";
        cout<<"3) Is Empty \n";
        cout<<"4) Is Full \n";
        cout<<"5) Display \n";
        cout<<"6) Peek \n";
        cout<<"7) Exit \n";
        cout<<"\nEnter your choice : ";
        cin>>ch;
        cout<<endl;
        switch(ch)
        {
            case 1:
                int a;
                cout<<"Enter data : ";
                cin>>a;
                s.push(a);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                if(s.isEmpty())
                    cout<<"Yes! Stack is empty!!! \n";
                else
                    cout<<"No! Stack is not empty!!! \n";
                break;
            case 4:
                if(s.isFull())
                    cout<<"Yes! Stack is full!!! \n";
                else
                    cout<<"No! Stack is not full!!! \n";
                break;
            case 5:
                s.display();
                break;
            case 6:
                cout<<"Data at top node : "<<s.peek()<<endl;
                break;
            case 7:
                exit(0);
            default:
                cout<<"Invalid choice! \n";
        }
        cout<<"\nDo you want to continue? (y/n) : ";
        cin>>c;
        system("cls");
    }while(c=='y'||c=='Y');
    return 0;
}
