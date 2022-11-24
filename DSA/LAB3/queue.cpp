#include <bits/stdc++.h>
using namespace std;
int rear = -1;
int front = 0;
void display(int queue[])
{
    for(int i=front;i<rear+1;i++)
    {
        cout << queue[i] << " ";
    }
    cout << "\n";
}
void push(int queue[], int n, int value)
{
    if(rear == n-1)
    {
        cout << "Overflow" << "\n";
    }
    else
    {
        queue[++rear] = value;
    }
}
void pop(int queue[])
{
    if(rear<front)
    {
        cout << "Underflow" << "\n";
    }
    else
    {
        front++;
    }
}
int main()
{
    int n;
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
                      push(queue,n,value);
                      break;
            case(2) : pop(queue);
                      break;   
            default : return 0;
        }
    }
}