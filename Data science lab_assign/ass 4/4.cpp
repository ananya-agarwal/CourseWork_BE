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
        top = NULL;
    }
    void push(char d);
    void pop();
    char peek();
    bool isEmpty();
};

void stack::push(char d)
{
    node *temp = new node;
    temp->data = d;
    temp->next = top;
    top = temp;
}

void stack::pop()
{
    if(top!=NULL)
    {
        node *temp = top;
        top = top->next;
        delete temp;
    }
}

char stack::peek()
{
    if(top!=NULL)
    {
        return top->data;
    }
}

bool stack::isEmpty()
{
    if(top == NULL)
        return true;
    return false;
}

int priority(char a)
{
    if(a == '^')
        return 3;
    else if((a == '*') || (a == '/') || (a == '%'))
        return 2;
    else if((a == '+') || (a == '-'))
        return 1;
    else
        return 0;
}

int main()
{
    int i;
    stack s;
    string expr;
    string postfix;
    cout<<"Enter the infix expression : ";
    getline(cin,expr);
    s.push('(');
    expr.push_back(')');
    for(i=0;expr[i]!='\0';i++)
    {
        if(expr[i] == ' ')
            continue;
        else if(expr[i] == '(')
            s.push(expr[i]);
        else if(expr[i] == ')')
        {
            while(s.peek()!='(')
            {
                postfix.push_back(s.peek());
                postfix.push_back(' '); // space gave so that while displaying we could separate the digits
                s.pop();
            }
            s.pop();//to pop '('
        }
        else if((expr[i] == '+') || (expr[i] == '-') || (expr[i] == '*') || (expr[i] == '/') || (expr[i] == '%') || (expr[i] == '^'))
        {
            while((priority(expr[i]) <= priority(s.peek())) && (s.peek()!='('))
            {
                postfix.push_back(s.peek());
                postfix.push_back(' '); // push back is already in string but in c++ some string related functions works ok with iostream only 
                s.pop();
            }
            s.push(expr[i]);// let say *- tha thus - toh using line no 99 gone in postfix expression but * toh stack mein aayega
        }
        else //for operands like a b c d etc.
        {
            postfix.push_back(expr[i]);
            postfix.push_back(' ');
        }
    }
    if(s.isEmpty())
        cout<<"\nPostfix Expression : "<<postfix<<endl;
    else
        cout<<"\nInvalid Expression! \n";
    return 0;
}
