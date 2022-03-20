#include<iostream>
#include<math.h>
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
    int EvaluatePostfix(string expr); // Function to evaluate Postfix expression and return output
    int PerformOperation(char operation, int operand1, int operand2);// Function to perform an operation and return output
    bool IsOperator(char C);// Function to verify whether a character is operator symbol or not
    bool IsNumericDigit(char C);// Function to verify whether a character is numeric digit or not
int main()
{
    string expr;
    cout<<"Enter Postfix Expression \n";
    //Enter expression with spaces
    //For eg. 2 10 *
    //Output = 20
    getline(cin,expr);
    
    int result = EvaluatePostfix(expr);
    cout<<"Output = "<<result<<"\n";
}

int EvaluatePostfix(string expr)
{
    int i;
    stack s;
    for(i=0;expr[i]!='\0';i++)
    {

        // Scanning each character from left and if character is a delimiter, move on
        if(expr[i] == ' ' || expr[i] == ',') 
		continue;

            // If character is operator, pop two elements from stack, perform operation and push the result into the stack again
        else if(IsOperator(expr[i]))
        {
            // Pop two operands
            int operand2 = s.peek(); s.pop();
            int operand1 = s.peek(); s.pop();
            // Perform operation
            int result = PerformOperation(expr[i], operand1, operand2);
            //Push back result of operation onto stack again
            s.push(result);
        }
        else if(IsNumericDigit(expr[i]))
        {
            // Extract the numeric operand from the string
            // Keep incrementing i as long as we are getting a numeric digit.
            int operand = 0;
            while(expr[i]!='\0' && IsNumericDigit(expr[i]))//like a no is 2 digit 20 thus will be considered as 20 only but 2 0 ..kyuki 2 baad no nahi hai 
            // thus pata chal gaya ki 2 digit no nahi hai with help of IsNumericDigit
            {
                // For a number with more than one digits, as we are scanning from left to right.
                // Everytime , we get a digit towards right, we can multiply current total in operand by 10
                // and add the new digit.
                operand = (operand*10) + (expr[i] - '0');//-0 beacuse like if number 2 hai i.e.50-48('0') lega uska varna sirf expr [i] 50 leta thus char to int conversion...example for 215 first of all 2 will come in stack
                // as only single operand can come at a time..then 2*10+1..then 21*10+5
                i++;
            }
            // Finally, you will come out of while loop with i set to a non-numeric character or end of string
            // decrement i because it will be incremented in increment section of for loop once again.
            // We do not want to skip the non-numeric character by incrementing i twice.
            i--;

            // Push operand on stack.
            s.push(operand);
        }
    }
    // If expression is in correct format, Stack will finally have one element. This will be the output.
    return s.peek();
}

// Function to verify whether a character is numeric digit.
bool IsNumericDigit(char C)
{
    if(C >= '0' && C <= '9')
    return true;
    return false;
}

// Function to verify whether a character is operator symbol or not.
bool IsOperator(char C)
{
    if(C == '+' || C == '-' || C == '*' || C == '/' || C == '^')
        return true;

    return false;
}

// Function to perform an operation and return output.
int PerformOperation(char operation, int operand1, int operand2)
{
    if(operation == '+') return operand1 +operand2;
    else if(operation == '-') return operand1 - operand2;
    else if(operation == '*') return operand1 * operand2;
    else if(operation == '/') return operand1 / operand2;
	else if(operation == '^') return pow(operand1,operand2);
    else cout<<"Unexpected Error \n";
    return -1;
}
