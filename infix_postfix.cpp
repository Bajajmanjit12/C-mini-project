#include<iostream>
#include<stack>
#include<string>
using namespace std;

int precendance(char op)
{
    if(op == '+' || op == '-')
    {
        return 1;
    }
    else if(op=='*'||op=='/')
    {
        return 2;
    }
    else if(op=='^')
    {
        return 3;
    }
    else
    {
        return 0;
    }

}

bool isOperator(char c)
{
    return(c=='+'||c=='-'||c=='*'||c=='/'||c=='^');
}

string infixToPostfix(string infix)
{
    stack<char> s;
    string postfix ="";

    for(int i=0;i<infix.length();i++)
    {
        char c=infix[i];

        if(isalnum(c))
        {
            postfix =postfix+c;
        }

        else if(c=='(')
        {
            s.push(c);
        }

        else if(c==')')
        {
            while(!s.empty() && s.top()=='(')
            {
                postfix=postfix+s.top();
                s.pop();
            }
            s.pop();
        }

        else if(isOperator(c))
        {
            while(!s.empty() && precendance(s.top())>=precendance(c))
            {
                postfix=postfix+s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    while(!s.empty())
    {
        postfix=postfix+s.top();
        s.pop();
    }

    return postfix;
}

int main()
{
    string infix;

    cout<<"\nEnter an infix expression:\n";
    cin>>infix;

    string postfix =infixToPostfix(infix);
    cout<<"\nPostfix expression:"<<postfix<<endl;

    return 0;
}