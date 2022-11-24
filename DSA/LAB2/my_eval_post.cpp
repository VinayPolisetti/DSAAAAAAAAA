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
int eval(int op1_val,char symbol,int op2_val)
{
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
bool is_digit(char ch)
{
    if((int)ch-'0' >= 0 && (int)ch-'0' <= 9)
    {
        return true;
    }
    return false;
}
int main()
{
    char postfix[1024];
    cout << "Enter the postfix exp. to evaluate with spaces seperating every operand and operator : ";
    scanf("%[^\n]s", postfix);
    int stack[strlen(postfix)+1];
    int top = -1;
    for(int i=0;i<strlen(postfix);i++)
    {
        if(postfix[i] == '-' && is_digit(postfix[i+1]))
        {
            int num = 0;
            i++;
			while(is_digit(postfix[i]))
			{
			    num = num * 10 + (int)(postfix[i] - '0');
				i++;
			}
            num = -num;
            stack[++top] = num;
        }
        else if(operator_check(postfix[i]))
        {
            int op2 = stack[top--];
            int op1 = stack[top--];
            int result = eval(op1,postfix[i],op2);
            stack[++top] = result;
            i++;
        }
        else
        {
            int num = 0;
			while(is_digit(postfix[i]))
			{
			    num = num * 10 + (int)(postfix[i] - '0');
				i++;
			}
            stack[++top] = num;
        }
    }
    cout << "The result of the postfix expression is " << stack[top];
}