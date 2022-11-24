#include <iostream>
#include <math.h>
using namespace std;
int exp(int op1, int op2)
{
    int res = 1;
    while(op2 != 0)
    {
        if(op2&1)
        {
            res *= op1;
        }
        op1 = op1*op1;
        op2 /= 2;
    }
    return res;
}
struct node
{
    int c,x,y,z;
    struct node* link;
};
typedef struct node* NODE;
int c,x,y,z;
NODE getnode(int c, int x, int y, int z)
{
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    if(temp == 0)
    {
        cout << "Out of Memory" << "\n";
        return temp;
    }
    temp->c = c;
    temp->x = x;
    temp->y = y;
    temp->z = z;
    temp->link = 0;
    return temp;
}
void insert_at_rear(int c, int x, int y, int z, NODE header)
{
    NODE temp = getnode(c,x,y,z);
    while(header->link != 0)
    {
        header = header->link;
    }
    header->link = temp;
}
void evaluate(NODE header)
{
    cout << "Enter the values of x,y,z for evaluation : ";
    cin >> x >> y >> z;
    NODE cur = header->link;
    int res = 0;
    while(cur != 0)
    {
        res += (cur->c) * exp(x,cur->x) * exp(y,cur->y) * exp(z,cur->z);
        cur = cur->link;
    }
    cout << "The result of the Expression is " << res << "\n";
}
void print(NODE header)
{
    cout << "The expression is as follows : " << "\n";
    NODE cur = header->link;
    while(cur != 0)
    {
        cout << cur->c << "x^" << cur->x << "y^" << cur->y << "z^" << cur->z;
        cur = cur->link;
        if(cur != 0)
        {
            cout << " + ";
        }
    }
    cout << "\n";
}
void input_an_exp(NODE header)
{
    while(1>0)
    {
        cout << "Enter c,x,y,z for term : ";
        cin >> c >> x >> y >> z;
        if (!c && !x && !y && !z)
        {
            break;
        }
        else
        {
            insert_at_rear(c, x, y, z, header);
        }
    }
}
void add()
{
    NODE header1 = getnode(0,0,0,0);
    cout << "Enter Expression1 : " << "\n";
    input_an_exp(header1);
    NODE header2 = getnode(0,0,0,0);
    cout << "Enter Expression2 : " << "\n";
    input_an_exp(header2);
    NODE cur1 = header1->link;
    while(cur1 != 0)
    {
        NODE prev = header2;
        NODE cur2 = header2->link;
        while(cur2 != 0)
        {
            if(cur1->x == cur2->x && cur1->y == cur2->y && cur1->z == cur2->z)
            {
                cur1->c += cur2->c;
                prev->link = cur2->link;
                free(cur2);
                break;
            }
            prev = cur2;
            cur2 = cur2->link;
        }
        cur1 = cur1->link;
    }
    NODE cur2 = header2->link;
    while(cur2 != 0)
    {
        insert_at_rear(cur2->c, cur2->x, cur2->y, cur2->z, header1);
        cur2 = cur2->link;
    }
    print(header1);
    evaluate(header1);
}
void multiply()
{
    NODE header1 = getnode(0,0,0,0);
    cout << "Enter Expression1 : " << "\n";
    input_an_exp(header1);
    NODE header2 = getnode(0,0,0,0);
    cout << "Enter Expression2 : " << "\n";
    input_an_exp(header2);
    NODE header3 = getnode(0,0,0,0);
    NODE cur1 = header1->link;
    while(cur1 != 0)
    {
        NODE cur2 = header2->link;
        while(cur2 != 0)
        {
            insert_at_rear(cur1->c*cur2->c, cur1->x+cur2->x, cur1->y+cur2->y, cur1->z+cur2->z, header3);
            cur2 = cur2->link;
        }
        cur1 = cur1->link;
    }
    cur1 = header3->link;
    while(cur1 != 0)
    {
        NODE prev = cur1;
        NODE cur2 = cur1->link;
        while(cur2 != 0)
        {
            if(cur1->x == cur2->x && cur1->y == cur2->y && cur1->z == cur2->z)
            {
                cur1->c += cur2->c;
                NODE temp = cur2->link;
                prev->link = temp;
                free(cur2);
                cur2 = temp;
            }
            else
            {
                prev = cur2;
                cur2 = cur2->link;
            }
        }
        cur1 = cur1->link;
    }
    print(header3);
    evaluate(header3);
}
int main()
{
    NODE header = getnode(0,0,0,0);
    int choice;
    while(1>0)
    {
        cout << "Enter your choice : " << "\n";
        cout << "1 - To enter the Polynomial" << "\n";
        cout << "2 - Evaluate the Expression" << "\n";
        cout << "3 - Print the Expression" << "\n";
        cout << "4 - Add Two Polynomials" << "\n";
        cout << "5 - Multiply Two Polynomials" << "\n";
        cout << "6 - Exit" << "\n";
        cin >> choice;
        switch(choice)
        {
            case(1) :   input_an_exp(header);
                        break;
            case(2) :   evaluate(header);
                        break;
            case(3) :   print(header);
                        break;
            case(4) :   add();
                        break;
            case(5) :   multiply();
                        break;
            case(6) :   return 0;
        }
    }
}