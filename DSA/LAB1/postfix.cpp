#include <bits/stdc++.h>
using namespace std;
int stack_precedence(char ch)
{
    switch(ch)
    {
        case('+') :
        case('-') : return 2;
        case('*') :
        case('/') : return 4;
        case('^') :
        case('$') : return 5;
        case('(') : return 0;
        case('#') : return -1;
        default   : return 8;
    }
}
int input_precedence(char ch)
{
    switch(ch)
    {
        case('+') :
        case('-') : return 1;
        case('*') :
        case('/') : return 3;
        case('^') :
        case('$') : return 6;
        case('(') : return 9;
        case(')') : return 0;
        default   : return 7;
    }
}
void inf_to_post(char input[], char postfix[])
{
    char stack[strlen(input)+1];
    int top_stack = -1;
    int top_postfix = -1;
    for(int i=0;i<strlen(input);i++)
    {
        while(stack_precedence((top_stack == -1) ? '#' : stack[top_stack]) > input_precedence(input[i]))
        {
            postfix[++top_postfix] = stack[top_stack--];
        }
        if(stack_precedence((top_stack == -1) ? '#' : stack[top_stack]) < input_precedence(input[i]))
        {
            stack[++top_stack] = input[i];
        }
        else
        {
            top_stack--;
        }
    }
    while(top_stack > -1)
    {
        postfix[++top_postfix] = stack[top_stack--];
    }
    postfix[++top_postfix] = '\0';
}
int main()
{
    char input[1024];
    cout << "Enter the Expression : ";
    cin >> input;
    char postfix[strlen(input)+1];
    inf_to_post(input,postfix);
    cout << "\nThe postfix expression for the given input expression is : " << postfix;
}
