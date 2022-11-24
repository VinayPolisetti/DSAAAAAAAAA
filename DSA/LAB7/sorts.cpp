#include <bits/stdc++.h>
using namespace std;
void insertion_sort(int arr[], int n)
{
    for(int i=1;i<n;i++)
    {
        int j = i-1;
        int key = arr[i];
        while(j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
        cout << "After Round" << (i) << " - ";
        for(int i=0;i<n;i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
}
void bubble_sort(int arr[] ,int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        cout << "After Round" << (i+1) << " - ";
        for(int i=0;i<n;i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
}
void selection_sort(int arr[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min = i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
        cout << "After Round" << (i+1) << " - ";
        for(int i=0;i<n;i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
}
int main()
{
    while(1>0)
    {
        int n, choice;
        cout << "Enter the size of the Integer array to sort in Non-Decreasing Order - ";
        cin >> n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cout << "Enter Element" << (i+1) << " : ";
            cin >> arr[i];
        }
        cout << "Enter 1 to sort the array in Insertion sort" << "\n";
        cout << "Enter 2 to sort the array in Bubble sort" << "\n";
        cout << "Enter 3 to sort the array in Selection sort" << "\n";
        cin >> choice;
        switch(choice)
        {
            case(1) : insertion_sort(arr, n);
                      break;
            case(2) : bubble_sort(arr, n);
                      break;
            case(3) : selection_sort(arr, n);
                      break;
            default : return 0;
        }
    }
}