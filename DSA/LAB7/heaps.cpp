#include <iostream>
using namespace std;
void bt_heapify(int arr[], int n, int choice)
{
    for(int i=(n/2)-1;i>=0;i--)
    {
        int key = arr[i];
        int p = i;
        int c = 2*p + 1;
        while(c < n)
        {
            if(c + 1 < n && (choice == 0 ? arr[c] < arr[c+1] : arr[c] > arr[c+1]))
            {
                c = c + 1;
            }
            if(choice == 0 ? key < arr[c] : key > arr[c])
            {
                arr[p] = arr[c];
                p = c;
                c = 2*p + 1;
            }
            else
            {
                break;
            }
        }
        arr[p] = key;
    }
}
void td_heapify(int arr[], int n, int choice)
{
    for(int i=1;i<n;i++)
    {
        int key = arr[i];
        int c = i;
        int p = (c-1)/2;
        while(c > 0 && (choice == 0 ? key > arr[p] : key < arr[p]))
        {
            arr[c] = arr[p];
            c = p;
            p = (c-1)/2;
        }
        arr[c] = key;
    }
}
void heap_sort(int arr[], int n, int choice)
{
    for(int i=n-1;i>0;i--)
    {
        bt_heapify(arr,i+1,choice);
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
    }
}
int main()
{
    int n;
    int choice;
    cout << "Enter the size of the array : ";
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cout << "Enter Element" << (i+1) << " : ";
        cin >> arr[i];
    }
    while(1>0)
    {
        cout << "Enter your Choice" << "\n";
        cout << "1 - Display the Heap" << "\n";
        cout << "2 - Create a Min Heap" << "\n";
        cout << "3 - Create a Max Heap" << "\n";
        cout << "4 - Top-Down Heapify" << "\n";
        cout << "5 - Bottom-Up Heapify" << "\n";
        cin >> choice;
        switch(choice)
        {
            case(1) : for(int i=0;i<n;i++)
                      {
                          cout << arr[i] << " ";
                      }
                      cout << "\n";
                      break;
            case(2) : heap_sort(arr, n, 0);
                      break;
            case(3) : heap_sort(arr, n, 1);
                      break;  
            case(4) : bt_heapify(arr, n, 0);
                      break;
            case(5) : td_heapify(arr, n, 0);
                      break; 
            default : return 0;
        }
    }
}
