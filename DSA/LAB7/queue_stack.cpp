#include <bits/stdc++.h>
using namespace std;
int top = -1;
int n;
void display(int stack[])
{
    for(int i=0;i<top+1;i++)
    {
        cout << stack[i] << " ";
    }
    cout << "\n";
}
void push(int stack[], int value)
{
    if(top == n-1)
    {
        cout << "Overflow" << "\n";
    }
    else
    {
        top = top + 1;
        stack[top] = value;
    }
}
int pop(int stack[])
{
    if(top == -1)
    {
        cout << "Underflow" << "\n";
        return -1;
    }
    else
    {
        return stack[top--];
    }
}
void this_display(int stack[])
{
    display(stack);
}
void this_push(int stack[], int value)
{
    push(stack,value);
}
int this_pop(int stack[])
{
    if(top == 0)
    {
        return pop(stack);
    }
    int temp = pop(stack);
    int popped = this_pop(stack);
    push(stack,temp);
    return popped;
}
int main()
{
    int temp;
    cout << "Enter the maximum number of elements in the Queue : ";
    cin >> n;
    int choice;
    int stack[n];
    while(1>0)
    {
        cout << "Enter your Choice" << "\n";
        cout << "0-display" << "\n";
        cout << "1-push" << "\n";
        cout << "2-pop" << "\n";
        cin >> choice;
        switch(choice)
        {
            case(0) : this_display(stack);
                      break;
            case(1) : int value;
                      cout << "Enter the value to push : ";
                      cin >> value;
                      this_push(stack,value);
                      break;
            case(2) : temp = this_pop(stack);
                      if(temp != -1)
                      {
                        cout << "The popped element is " << temp << "\n";
                      }
                      break;   
            default : return 0;
        }
    }
}