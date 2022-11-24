#include <iostream>
#include <cstring>
using namespace std;
#define min(a,b) ((a<b)?a:b)
struct node
{
    int roll;
    int sem;
    int phone;
    char name[25];
    char branch[25];
    struct node* link;
};
typedef struct node* NODE;
void string_copy(char arr1[], char arr2[])
{
    int i=0;
    for(i=0;i<min(24,strlen(arr2));i++)
    {
        arr1[i] = arr2[i];
    }
    arr1[i] = '\0';
}
NODE getnode(int roll, int sem, int phone, char name[], char branch[])
{
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    if(temp == 0)
    {
        cout << "Out of Memory" << "\n";
        return temp;
    }
    temp->roll = roll;
    temp->sem = sem;
    temp->phone = phone;
    string_copy(temp->name,name);
    string_copy(temp->branch,branch);
    return temp;
}
void insert_at_front(int roll,int sem,int phone, char name[], char branch[], NODE header)
{
    NODE temp = getnode(roll, sem, phone, name, branch);
    temp->link = header->link;
    header->link = temp;
}
void insert_at_rear(int roll,int sem,int phone, char name[], char branch[], NODE header)
{
    NODE temp = getnode(roll, sem, phone, name, branch);
    NODE cur = header->link;
    if(cur == 0)
    {
        header->link = temp;
    }
    else
    {
        while(cur->link != 0)
        {
            cur = cur->link;
        }
        cur->link = temp;
    }
}
void delete_at_front(NODE header)
{
    if(header->link == 0)
    {
        cout << "List is Empty" << "\n";
    }
    else
    {
        NODE first = header->link;
        NODE temp = first->link;
        free(first);
        header->link = temp;
    }
}
void delete_at_rear(NODE header) // remember that without header, you got to include seperate case for single node present
{
    if(header->link == 0)
    {
        cout << "List is Empty" << "\n";
    }
    else
    {
        NODE cur = header->link;
        NODE prev = header;
        while(cur->link != 0)
        {
            prev = cur;
            cur = cur->link;
        }
        free(cur);
        prev->link = 0;
    }
}
int display_count(NODE header)
{
    int ctr = 0;
    if(header->link == 0)
    {
        cout << "\n";
    }
    else
    {
        NODE cur = header->link;
        while(cur != 0)
        {
            cout << cur->roll << " " << cur->sem  << " " << cur->phone << " " << cur->name << " " << cur->branch << "\n";
            cur = cur->link;
            ctr++;
        }
    }
    return ctr;
}
int roll,sem,phone;
char name[25], branch[25];
void take_input()
{
    cout << "Enter Roll, Sem, Phone Number, Name, Branch orderly : ";
    cin >> roll >> sem >> phone;
    scanf("%s %s", name, branch);
}
void deque_sll(NODE header)
{
    int choice1,choice2,total;
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
            case(0) : total = display_count(header);
                      cout << "The Number of students/nodes in the DLL is " << total << "\n";
                      break;
            case(1) : take_input();
                      (choice1==0)?(insert_at_front(roll,sem,phone,name,branch,header)):(insert_at_rear(roll,sem,phone,name,branch,header));
                      break;
            case(2) : (choice1==0)?(delete_at_front(header)):(delete_at_rear(header));
                      break;   
            default : return;
        }
    }
}
int main()
{
    NODE header = getnode(roll,sem,phone,name,branch);
    int choice,len,ctr;
    while(1>0)
    {
        cout << "Enter your choice : " << "\n";
        cout << "1 - Create SSL of N-students by front insertion" << "\n";
        cout << "2 - Display the contents of the SLL and Count the number of Nodes" << "\n";
        cout << "3 - Insertion at Rear end of SLL" << "\n";
        cout << "4 - Deletion at Rear end of SLL" << "\n";
        cout << "5 - Insertion at Front end of SLL" << "\n";
        cout << "6 - Deletion at Front end of SLL" << "\n";
        cout << "7 - Demonstrate deque using SLL" << "\n";
        cout << "8 - Exit" << "\n";
        cin >> choice;
        switch(choice)
        {
            case(1) :   cout << "Enter No. of Students : ";
                        cin >> len;
                        for(int i=0;i<len;i++)
                        {
                            take_input();
                            insert_at_front(roll,sem,phone,name,branch,header);
                        }
                        break;
            case(2) :   ctr = display_count(header);
                        cout << "The Number of students/nodes in the SLL is " << ctr << "\n";
                        break;
            case(3) :   take_input();
                        insert_at_rear(roll,sem,phone,name,branch,header);
                        break;
            case(4) :   delete_at_rear(header);
                        break;
            case(5) :   take_input();
                        insert_at_front(roll,sem,phone,name,branch,header);
                        break;
            case(6) :   delete_at_front(header);
                        break;
            case(7) :   deque_sll(header);
                        break;
            case(8) :   return 0;
        }
    }
}