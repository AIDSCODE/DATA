#include<iostream>
using namespace std;

class stack
{
public:
    int s[10];
    int top,max;

    stack()
    {
        max = 5;
        top = -1;
    }

    void push(char);
    char pop();
    int isempty();
    int isfull();
    void check(char ex[]); 
};


int stack::isempty()
{
    if (top == -1)
    {
        return 1;
    } 
	else 
	{
        return 0;
    }
}

int stack::isfull()
{
    if (top == max - 1)
    {
        return 1;
    }
	 else
	{
        return 0;
    }
}

void stack::push(char e)
 {
    if (!isfull())
    {
        top++;
        s[top] = e;
    }
	 else 
    {
        cout << "Stack is full\n";
    }
}

char stack::pop() 
{
    if (!isempty()) 
    { 
        return s[top--];
    } 
	else
    {
        return -1;
    }
}


void stack::check(char ex[]) 
{
    int i = 0;
    char cur, del;
    int f = 0;

    while (ex[i] != '\0')
    { 
        cur = ex[i];

        if (cur == '(' || cur == '[' || cur == '{') {
            push(cur);
        }

        if (cur == ')' || cur == ']' || cur == '}') {
            del = pop();
            if (!((cur == ')' && del == '(') ||
                  (cur == ']' && del == '[') ||
                  (cur == '}' && del == '{'))) 
                  {
                f = 1;
                break;
            }
        }
        i++;
    }

    if (isempty() && f == 0)
    { 
        cout << "well parenthesized"<<endl;
    }
	 else 
	{
        cout << "not parenthesized"<<endl;
    }
}

int main()
 {
    stack s;
    char ex[10];
    cout << "Enter the Expression that you want to check:";
    cin >> ex;
    s.check(ex); 
}

