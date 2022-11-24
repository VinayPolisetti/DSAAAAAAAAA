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
    struct node* l;
    struct  node* r;
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
int string_cmp(char arr1[], char arr2[])
{
    if(strlen(arr1) != strlen(arr2))
    {
        return 0;
    }
    for(int i=0;i<strlen(arr1);i++)
    {
        if(arr1[i] != arr2[i])
        {
            return 0;
        }
    }
    return 1;
}
int cmp(NODE req, int roll, int sem, int phone, char name[], char branch[])
{
    if(req->roll == roll && req->sem == sem && req->phone == phone && string_cmp(req->name, name) && string_cmp(req->branch, branch))
    {
        return 1;
    }
    return 0;
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
    if(header->r == 0)
    {
        temp->r = header->r;
        header->r = temp;
        temp->l = header;
    }
    else
    {
        NODE cur = header->r;
        temp->r = cur;
        header->r = temp;
        temp->l = header;
        cur->l = temp;
    }
}
void insert_at_rear(int roll,int sem,int phone, char name[], char branch[], NODE header)
{
    NODE temp = getnode(roll, sem, phone, name, branch);
    NODE cur = header->r;
    if(cur == 0)
    {
        header->r = temp;
        temp->l = header;
    }
    else
    {
        while(cur->r != 0)
        {
            cur = cur->r;
        }
        cur->r = temp;
        temp->r = 0;
        temp->l = cur;
    }
}
void delete_at_front(NODE header)
{
    NODE first = header->r;
    if(first == 0)
    {
        cout << "List is Empty" << "\n";
    }
    else
    {
        NODE cur = first->r;
        free(first);
        header->r = cur;
        if(cur != 0)
        {
            cur->l = header;
        }
    }
}
void delete_at_rear(NODE header)
{
    NODE prev = header;
    NODE cur = header->r;
    if(cur == 0)
    {
        cout << "List is Empty" << "\n";
    }
    else
    {
        while(cur->r != 0)
        {
            prev = cur;
            cur = cur->r;
        }
        prev->r = 0;
        free(cur);
    }
}
int display_count(NODE header)
{
    int ctr = 0;
    NODE cur = header->r;
    if(cur == 0)
    {
        cout << "\n";
    }
    else
    {
        while(cur != 0)
        {
            cout << cur->roll << " " << cur->sem  << " " << cur->phone << " " << cur->name << " " << cur->branch << "\n";
            cur = cur->r;
            ctr++;
        }
    }
    return ctr;
}
void insert_after(int roll,int sem,int phone, char name[], char branch[], 
                    int roll1,int sem1,int phone1, char name1[], char branch1[], NODE header)
{
    NODE temp = getnode(roll1, sem1, phone1, name1, branch1);
    NODE cur = header->r;
    while(cur != 0)
    {
        if(cmp(cur,roll,sem,phone,name,branch))
        {
            temp->r = cur->r;
            cur->r = temp;
            temp->l = cur;
            break;
        }
        cur = cur->r;
    }
    if(cur == 0)
    {
        cout << "No such node with given details exists" << "\n";
    }
}
int roll,sem,phone;
char name[25], branch[25];
int roll1,sem1,phone1;
char name1[25], branch1[25];
void take_input()
{
    cout << "Enter Roll, Sem, Phone Number, Name, Branch orderly : ";
    cin >> roll >> sem >> phone;
    scanf("%s %s", name, branch);
}
void deque_dll(NODE header)
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
    header->r = 0;
    header->l = 0;
    int choice,len,ctr;
    while(1>0)
    {
        cout << "Enter your choice : " << "\n";
        cout << "1 - Create DLL of N-students by front insertion" << "\n";
        cout << "2 - Display the contents of the DLL and Count the number of Nodes" << "\n";
        cout << "3 - Insertion at Rear end of DLL" << "\n";
        cout << "4 - Deletion at Rear end of DLL" << "\n";
        cout << "5 - Insertion at Front end of DLL" << "\n";
        cout << "6 - Deletion at Front end of DLL" << "\n";
        cout << "7 - Demonstrate deque using DLL" << "\n";
        cout << "8 - Insert a Node after the given Node" << "\n";
        cout << "9 - Exit" << "\n";
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
                        cout << "The Number of students/nodes in the DLL is " << ctr << "\n";
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
            case(7) :   deque_dll(header);
                        break;
            case(8) :   cout << "Enter the details of the node to insert a node after it : ";
                        take_input();
                        cout << "Enter the details of the node to insert : ";
                        cin >> roll1 >> sem1 >> phone1;
                        scanf("%s %s", name1, branch1);
                        insert_after(roll,sem,phone,name,branch,roll1,sem1,phone1,name1,branch1,header);
                        break;
            case(9) :   return 0;
        }
    }
}