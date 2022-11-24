#include <bits/stdc++.h>
using namespace std;
bool operator_check(char symbol)
{
    char op[] = "+-*%/x$^";
    for(int i=0;i<strlen(op);i++)
    {
        if(symbol == op[i])
        {
            return true;
        }
    }
    return false;
}
int exp(int op1, int op2)
{
    int res = 1;
    while(op2 != 0)
    {
        if(op2&1)
        {
            res *= op1;
        }
        op1 = op1*op1;
        op2 /= 2;
    }
    return res;
}
int eval(char op1,char symbol,char op2)
{
    int op1_val = op1-'0';
    int op2_val = op2-'0';
    switch(symbol)
    {
        case('+') : return op1_val+op2_val;
        case('-') : return op1_val-op2_val;
        case('x') :
        case('*') : return op1_val*op2_val;
        case('%') :
        case('/') : return op1_val/op2_val;
        case('^') :
        case('$') : return exp(op1_val,op2_val);
    }
}
int main()
{
    char postfix[1024];
    cout << "Enter the postfix to evaluate : ";
    scanf("%s", postfix);
    char stack[strlen(postfix)+1];
    int top = -1;
    for(int i=0;i<strlen(postfix);i++)
    {
        if(operator_check(postfix[i]))
        {
            char op2 = stack[top--];
            char op1 = stack[top--];
            int result = eval(op1,postfix[i],op2);
            stack[++top] = '0' + result;
        }
        else
        {
            stack[++top] = postfix[i];
        }
    }
    cout << "The result of the postfix expression is " << stack[top];
}