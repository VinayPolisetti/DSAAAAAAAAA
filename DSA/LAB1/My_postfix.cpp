#include <bits/stdc++.h>
using namespace std;
int precedence(char ch, bool is_stack)
{
    switch(ch)
    {
        case('+') :
        case('-') : return (is_stack == true ? 2 : 1);
        case('*') :
        case('/') : return (is_stack == true ? 4 : 3);
        case('^') :
        case('$') : return (is_stack == true ? 5 : 6);
        case('(') : return (is_stack == true ? 0 : 9);
        case(')') : return 0;
        case('#') : return -1;
        default   : return (is_stack == true ? 8 : 7);
    }
}
int main()
{
    char input[1024];
    cout << "Enter the Expression : ";
    cin >> input;
    cout << strlen(input) << "\n";
    char stack[strlen(input)+1];
    char postfix[strlen(input)+1];
    int top_stack = -1;
    int top_postfix = -1;
    for(int i=0;i<strlen(input);i++)
    {
        while(precedence((top_stack == -1) ? '#' : stack[top_stack],true) < precedence(input[i],false))
        {
            stack[++top_stack] = input[i++];
        }
        if(precedence((top_stack == -1) ? '#' : stack[top_stack],true) == precedence(input[i],false))
        {
            top_stack--;
        }
        else
        {
            postfix[++top_postfix] = stack[top_stack--];
            i--;
        }
    }
    while(top_stack > -1)
    {
        postfix[++top_postfix] = stack[top_stack--];
    }
    postfix[++top_postfix] = '\0';
    cout << "\nThe postfix expression for the given input expression is : " << postfix;
}
