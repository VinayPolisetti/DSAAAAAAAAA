#include <bits/stdc++.h>
using namespace std;
int stack_precedence(char ch)
{
    switch(ch)
    {
        case('+') :
        case('-') : return 1;
        case('*') :
        case('/') : return 3;
        case('^') :
        case('$') : return 6;
        case(')') : return 0;
        case('#') : return -1;
        default   : return 8;
    }
}
int input_precedence(char ch)
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
        case(')') : return 9;
        default   : return 7;
    }
}
void reverse(char arr[])
{
    int p=0,q=strlen(arr)-1;
    while(p<q)
    {
        int temp = arr[p];
        arr[p] = arr[q];
        arr[q] = temp;
        p++;
        q--;
    }
}
void inf_to_pre(char input[], char prefix[])
{
    char stack[strlen(input)+1];
    int top_stack = -1;
    int top_prefix = -1;
    for(int i=0;i<strlen(input);i++)
    {
        while(stack_precedence((top_stack == -1) ? '#' : stack[top_stack]) > input_precedence(input[i]))
        {
            prefix[++top_prefix] = stack[top_stack--];
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
        prefix[++top_prefix] = stack[top_stack--];
    }
    prefix[++top_prefix] = '\0';
}
int main()
{
    char input[1024];
    cout << "Enter the Expression : ";
    cin >> input;
    char prefix[strlen(input)+1];
    reverse(input);
    inf_to_pre(input, prefix);
    reverse(prefix);
    cout << "\nThe prefix expression for the given input expression is : " << prefix;
}
