#include <bits/stdc++.h>
using namespace std;
int size = 1;
int *my_stack = (int*)malloc(sizeof(int)*size);
int top = -1;
void push(int element)
{
    if(top == size-1)
    {
        cout << "Overflow" << "\n";
        cout << "Increasing the size of the stack" << "\n";
        size += 1;
        my_stack = (int*)realloc(my_stack,sizeof(int)*size);
        push(element);
    }
    else
    {
        my_stack[++top] = element;
    }
}
void pop()
{
    if(top == -1)
    {
        cout << "Undeflow" << "\n";
    }
    else
    {
        top--;
    }
}
void display()
{
    if(top == -1)
    {
        cout << "Empty Stack" << "\n";
        return;
    }
    for(int i=0;i<top+1;i++)
    {
        cout << my_stack[i] << " ";
    }
    cout << "\n";
}
int main()
{
    while(1>0)
    {
        int choice;
        cout << "Enter\n\"2\" to display the stack\n\"1\" to push an element\n\"0\" to pop an element : ";
        cin >> choice;
        if(choice == 2)
        {
            display();
        }
        else if(choice == 1)
        {
            int element;
            cout << "Enter an element to push into the stack : ";
            cin >> element;
            push(element);
        }
        else
        {
            pop();
        }
    }
}