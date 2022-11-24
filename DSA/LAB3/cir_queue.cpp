#include <bits/stdc++.h>
using namespace std;
int rear = -1;
int front = 0;
int ctr = 0;
int n;
void display(int queue[])
{
    for(int i=front;i<front+ctr;i++)
    {
        cout << queue[i%n] << " ";
    }
    cout << "\n";
}
void push(int queue[], int value)
{
    if(ctr == n)
    {
        cout << "Overflow" << "\n";
    }
    else
    {
        rear = (rear+1)%n;
        queue[rear] = value;
        ctr++;
    }
}
void pop(int queue[])
{
    if(ctr == 0)
    {
        cout << "Underflow" << "\n";
    }
    else
    {
        front = (front+1)%n;
        ctr--;
    }
}
int main()
{
    cout << "Enter the maximum number of elements in the Queue : ";
    cin >> n;
    int queue[n];
    int choice;
    int value;
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
            case(1) : cout << "Enter the value to push : ";
                      cin >> value;
                      push(queue,value);
                      break;
            case(2) : pop(queue);
                      break;   
            default : return 0;
        }
    }
}