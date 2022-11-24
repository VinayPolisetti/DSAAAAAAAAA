#include <bits/stdc++.h>
using namespace std;
int rear = -1;
int front = 0;
int n;
void display(int queue[])
{
    for(int i=front;i<rear+1;i++)
    {
        cout << queue[i%n] << " ";
    }
    cout << "\n";
}
void push(int queue[], int value)
{
    if(rear-front+1 == n)
    {
        cout << "Overflow" << "\n";
    }
    else
    {
        rear = rear+1;
        queue[rear%n] = value;
    }
}
void pop(int queue[])
{
    if(front>rear)
    {
        cout << "Underflow" << "\n";
    }
    else
    {
        front = front + 1;
    }
}
int main()
{
    cout << "Enter the maximum number of elements in the Queue : ";
    cin >> n;
    int queue[n];
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
            case(0) : display(queue);
                      break;
            case(1) : int value;
                      cout << "Enter the value to push : ";
                      cin >> value;
                      push(queue,value);
                      break;
            case(2) : pop(queue);
                      break;   
            default : return 0;
        }
    }
}