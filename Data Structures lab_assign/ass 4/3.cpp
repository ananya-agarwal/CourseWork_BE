#include<iostream>
using namespace std;

struct node
{
    char data;
    node *next;
} ;

class stack
{
    node *top;
    public:
    stack()
    {
        top = NULL;
    }
    void push(char ch);
    void pop();
    char peek();
    bool isEmpty();
};

void stack::push(char ch)
{
    node *temp = new node;
    temp->data = ch;
    temp->next = top;
    top = temp;
}

void stack::pop()
{
    if(!isEmpty())
    {
        node *temp = top;
        top = top->next;
        delete temp;
    }
}

char stack::peek()
{
    if(!isEmpty())
        return top->data;
}

bool stack::isEmpty()
{
    if(top == NULL)
        return true;
    return false;
}

int main()
{
    int i;
    stack s;
    string expr;
    cout<<"Enter the expression : ";
    getline(cin,expr);
    for(i=0;expr[i]!='\0';i++)
    {
        if(expr[i] == ' ')
            continue;
        else if(s.isEmpty() == true)
            s.push(expr[i]);
        else if((s.peek() == '(' && expr[i] == ')') || (s.peek() == '[' && expr[i] == ']') || (s.peek() == '{' && expr[i] == '}'))
            s.pop();
        else
            s.push(expr[i]);
    }
    if(s.isEmpty() == true)
        cout<<"\nThe given expression is balanced!!!!\n";
    else
        cout<<"\nThe given expression is not balanced!!!! \n";
    return 0;
}
