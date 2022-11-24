#include <iostream>
using namespace std;
int front = 0;
int rear = -1;
int n = 1024;
int queue[1024];
int size()
{
    return rear-front+1;
}
void display()
{
    for(int i=front;i<rear+1;i++)
    {
        cout << queue[i] << " ";
    }
    cout << "\n";
}
void push(int val)
{
    if(rear == n-1)
    {
        cout << "Overflow" << "\n";
    }
    else
    {
        queue[++rear] = val;
    }
}
int pop()
{
    if(front > rear)
    {
        cout << "Underflow" << "\n";
        return -1;
    }
    else
    {
        return queue[front++];
    }
}
void this_push(int val)
{
    push(val);
}
int this_pop(int size)
{
    if(size == 1 || size == 0)
    {
        return pop();
    }
    int popped = pop();
    push(popped);
    return this_pop(size-1);
}
void this_display()
{
    display();
}
int main()
{
    int value, popped;
    int choice;
    while(1>0)
    {
        cout << "Enter your Choice" << "\n";
        cout << "0-display" << "\n";
        cout << "1-push" << "\n";
        cout << "2-pop" << "\n";
        cin >> choice;
        switch(choice)
        {
            case(0) : this_display();
                      break;
            case(1) : int value;
                      cout << "Enter the value to push : ";
                      cin >> value;
                      this_push(value);
                      break;
            case(2) : popped = this_pop(size());
                      if(popped != -1)
                      {
                        cout << "The popped element is " << popped << "\n";
                      }
                      break;   
            default : return 0;
        }
    }
}