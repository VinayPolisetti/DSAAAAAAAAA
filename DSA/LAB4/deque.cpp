#include <bits/stdc++.h>
using namespace std;
int rear = -1;
int front = 0;
int n;
void display(int queue[])
{
    for(int i=front;i<rear+1;i++)
    {
        cout << queue[i] << " ";
    }
    cout << "\n";
}
void push(int queue[], int value, int choice)
{
    if(choice == 0)
    {
        if(front == 0 && rear == -1)
        {
            rear = rear + 1;
            queue[rear] = value;
        }
        else if(front != 0)
        {
            front = front - 1;
            queue[front] = value;
        }
        else
        {
            cout << "Overflow" << "\n";
        }
    }
    else if(choice == 1)
    {
        if(rear == n-1)
        {
            cout << "Overflow" << "\n";
        }
        else
        {
            rear = rear + 1;
            queue[rear] = value;
        }
    }
}
void pop(int queue[], int choice)
{
    if(choice == 0)
    {
        if(front > rear)
        {
            cout << "Underflow" << "\n";
        }
        else
        {
            front++;
            if(front > rear)
            {
                front = 0;
                rear = -1;
            }
        }
    }
    else if(choice == 1)
    {
        if(front > rear)
        {
            cout << "Underflow" << "\n";
        }
        else
        {
            rear--;
            if(front > rear)
            {
                front = 0;
                rear = -1;
            }
        }
    }
}
int main()
{
    cout << "Enter the maximum number of elements in the Queue : ";
    cin >> n;
    int queue[n];
    int choice1,choice2;
    while(1>0)
    {
        cout << "Enter your Choice" << "\n";
        cout << "0-front && 1-rear" << "\n";
        cout << "0-display" << "\n";
        cout << "1-push" << "\n";
        cout << "2-pop" << "\n";
        cin >> choice1 >> choice2;
        switch(choice2)
        {
            case(0) : display(queue);
                      break;
            case(1) : int value;
                      cout << "Enter the value to push : ";
                      cin >> value;
                      push(queue,value,choice1);
                      break;
            case(2) : pop(queue,choice1);
                      break;   
            default : return 0;
        }
    }
}