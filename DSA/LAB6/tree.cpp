#include <iostream>
using namespace std;
#define max(a,b) (a>b ? a : b);
struct node
{
    int inf;
    struct node* l;
    struct node* r;
};
typedef struct node* NODE;
NODE getnode(int inf)
{
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    if(temp == 0)
    {
        cout << "Out of Memory" << "\n";
        return temp;
    }
    temp->inf = inf;
    temp->l = 0;
    temp->r = 0;
    return temp;
}
NODE create_bt()
{

    int inf;
    cout << "Enter the Inf : ";
    cin >> inf;
    if(inf < 0)
    {
        return 0;
    }
    NODE temp = getnode(inf);
    cout << "Enter the left child of " << inf << " : ";
    temp->l = create_bt();
    cout << "Enter the Right child of " << inf << " : ";
    temp->r = create_bt();
    return temp;
}
NODE add_bst(NODE root, int inf)
{
    NODE cur = root;
    NODE item = getnode(inf);
    NODE parent = NULL;
    while(cur != 0)
    {
        if(inf <= cur->inf)
        {
            parent = cur;
            cur = cur->l;
        }
        else
        {
            parent = cur;
            cur = cur->r;
        }
    }
    if(parent == 0)
    {
        return item;
    }
    if(inf <= parent->inf)
    {
        parent->l = item;
    }
    else
    {
        parent->r = item;
    }
    return root;
}
NODE del_bst(NODE root, int inf)
{
    if(root == 0)
    {
        cout << "The tree is Null" << "\n";
        return NULL;
    }
    NODE parent = 0;
    NODE cur = root;
    while(cur != 0)
    {
        if(cur->inf == inf)
        {
            break;
        }
        parent = cur;
        if(cur->inf < inf)
        {
            cur = cur->r;
        }
        else
        {
            cur = cur->l;
        }
    }
    NODE q = 0;
    if(cur == 0)
    {
        cout << "Required Node is not Present in the Tree" << "\n";
        return NULL;
    }
    else if(cur->l == 0) // If no childs are present, it will execute here and q becomes NULL
    {
        q = cur->r;
    }
    else if(cur->r == 0)
    {
        q = cur->l;
    }
    else // Attaching left link of to be deleted node at the in-order successor 
    {
        NODE suc = cur->r;
        q = cur->r;
        while(suc->l != 0)
        {
            suc = suc->l;
        }
        suc->l = cur->l;
    }
    if(parent == 0)
    {
        free(cur);
        return q;
    }
    else
    {
        if(parent->l == cur)
        {
            parent->l = q;
        }
        else
        {
            parent->r = q;
        }
        free(cur);
        return root;
    }
}
int height(NODE root)
{
    if(root == 0)
    {
        return -1;
    }
    return 1 + max(height(root->l), height(root->r));
}
int num_nodes(NODE root)
{
    if(root == 0)
    {
        return 0;
    }
    return 1 + num_nodes(root->l) + num_nodes(root->r);
}
int num_leaf(NODE root)
{
    if(root == 0)
    {
        return 0;
    }
    if(root->l == 0 && root->r == 0)
    {
        return 1;
    }
    return num_leaf(root->l) + num_leaf(root->r);
}
NODE search_bst(NODE root, int inf)
{
    if(root == 0)
    {
        return NULL;
    }
    if(root->inf == inf)
    {
        return root;
    }
    else if(root->inf > inf)
    {
        return search_bst(root->l, inf);
    }
    else
    {
        return search_bst(root->r, inf);
    }
}
void preorder(NODE root)
{
    if(root == NULL)
    {
        return;
    }
    cout << root->inf << " ";
    preorder(root->l);
    preorder(root->r);
}
void inorder(NODE root)
{
    if(root == NULL)
    {
        return;
    }
    inorder(root->l);
    cout << root->inf << " ";
    inorder(root->r);
}
void postorder(NODE root)
{
    if(root == NULL)
    {
        return;
    }
    postorder(root->l);
    postorder(root->r);
    cout << root->inf << " ";
}
void iterative_preorder(NODE root)
{
    int top = -1;
    NODE stack[1024];
    NODE cur = root;
    while(1>0)
    {
        while(cur != 0)
        {
            cout << cur->inf << " ";
            stack[++top] = cur;
            cur = cur->l;
        }
        if(top > -1)
        {
            cur = stack[top--];
            cur = cur->r;
        }
        else
        {
            return;
        }
    }
}
void iterative_inorder(NODE root)
{
    int top = -1;
    NODE stack[1024];
    NODE cur = root;
    while(1>0)
    {
        while(cur != 0)
        {
            stack[++top] = cur;
            cur = cur->l;
        }
        if(top > -1)
        {
            cur = stack[top--];
            cout << cur->inf << " ";
            cur = cur->r;
        }
        else
        {
            return;
        }
    }
}
void iterative_postorder(NODE root)
{
    int top = -1;
    NODE stack[1024];
    NODE cur = root;
    while(1>0)
    {
        while(cur != 0)
        {
            stack[++top] = cur;
            stack[++top] = cur;
            cur = cur->l;
        }
        if(top > -1)
        {
            cur = stack[top--];
            if(stack[top] == cur)
            {
                cur = cur->r;
            }
            else
            {
                cout << cur->inf << " ";
                cur = 0;
            }
        }
        else
        {
            return;
        }
    }
}
NODE in_successor_bst(NODE root, int inf)
{
    NODE req = search_bst(root, inf);
    if(req == 0)
    {
        cout << "Node Not Found" << "\n";
        return NULL;
    }
    if(req->r != 0)
    {
        NODE suc = req->r;
        while(suc->l != 0)
        {
            suc = suc->l;
        }
        return suc;
    }
    NODE parent = NULL;
    NODE cur = root;
    while(cur != 0 && cur != req)
    {
        if(cur->inf > req->inf)
        {
            parent = cur;
            cur = cur->l;
        }
        else
        {
            cur = cur->r;
        }
    }
    return parent;
}
NODE in_predecessor_bst(NODE root, int inf)
{
    NODE req = search_bst(root, inf);
    if(req == 0)
    {
        cout << "Node Not Found" << "\n";
        return NULL;
    }
    if(req->l != 0)
    {
        NODE pre = req->l;
        while(pre->r != 0)
        {
            pre = pre->r;
        }
        return pre;
    }
    NODE parent = NULL;
    NODE cur = root;
    while(cur != 0 && cur != req)
    {
        if(cur->inf > req->inf)
        {
            cur = cur->l;
        }
        else
        {
            parent = cur;
            cur = cur->r;
        }
    }
    return parent;
}
NODE min_bst(NODE root)
{
    if(root == 0)
    {
        cout << "Null Tree" << "\n";
        return NULL;
    }
    NODE cur = root;
    while(cur->l != 0)
    {
        cur = cur->l;
    }
    return cur;
}
NODE max_bst(NODE root)
{
    if(root == 0)
    {
        cout << "Null Tree" << "\n";
        return NULL;
    }
    NODE cur = root;
    while(cur->r != 0)
    {
        cur = cur->r;
    }
    return cur;
}
int main()
{
    int choice,inf;
    NODE temp = 0;
    NODE root = 0;
    while(1>0)
    {
        cout << "Enter your choice : " << "\n";
        cout << "1 - Add nodes to the Binary Search Tree" << "\n";
        cout << "2 - Delete a node from the Binary Search Tree" << "\n";
        cout << "3 - Iterative Traversals" << "\n";
        cout << "4 - Recursive Traversals" << "\n";
        cout << "5 - Min and Max Node of BST" << "\n";
        cout << "6 - Inorder Successor and Predecessor of a Node in BST" << "\n";
        cout << "7 - Height, Number of Nodes and Leaf Nodes in Binary Tree" << "\n";
        cout << "8 - Search for a Node in Binary Search Tree" << "\n";
        cout << "9 - Create a Binary Tree" << "\n";
        cout << "10 - Exit" << "\n";
        cin >> choice;
        switch(choice)
        {
            case(1) :   cout << "Enter the Inf of the node to be added : ";
                        cin >> inf;
                        root = add_bst(root, inf);
                        break;
            case(2) :   cout << "Enter the Inf of the node to be deleted : ";
                        cin >> inf;
                        root = del_bst(root, inf);
                        break;
            case(3) :   iterative_preorder(root);
                        cout << "\n";
                        iterative_inorder(root);
                        cout << "\n";
                        iterative_postorder(root);
                        cout << "\n";
                        break;
            case(4) :   preorder(root);
                        cout << "\n";
                        inorder(root);
                        cout << "\n";
                        postorder(root);
                        cout << "\n";
                        break;
            case(5) :   temp = min_bst(root);
                        if(temp != 0)
                        {
                            cout << "The Min Node present in the tree - " << temp->inf << "\n";
                        }
                        temp = max_bst(root);
                        if(temp != 0)
                        {
                            cout << "The Max Node present in the tree - " << temp->inf << "\n";
                        }
                        break;
            case(6) :   cout << "Enter the Node's Inf to get it\'s predecessor & successor : ";
                        cin >> inf;
                        temp = in_predecessor_bst(root, inf);
                        cout << "The In-Order predecessor of the given Node with Inf-" << inf << " is : "; 
                        if(temp == 0)
                        {
                            cout << "Not Found";
                        }
                        else
                        {
                            cout << temp->inf;
                        }
                        cout << "\n";
                        temp = in_successor_bst(root, inf);
                        cout << "The In-Order successor of the given Node with Inf-" << inf << " is : "; 
                        if(temp == 0)
                        {
                            cout << "Not Found";
                        }
                        else
                        {
                            cout << temp->inf;
                        }
                        cout << "\n";
                        break;
            case(7) :   cout << "The Height of the given Binary Tree is : " << height(root) << "\n";
                        cout << "The Number of Nodes of the given Binary Tree is : " << num_nodes(root) << "\n";
                        cout << "The Number of Leaf Nodes of the given Binary Tree is : " << num_leaf(root) << "\n";
                        break;
            case(8) :   cout << "Enter the Inf of the node to find : ";
                        cin >> inf;
                        temp = search_bst(root, inf);
                        if(temp == 0)
                        {
                            cout << "Node not Found with Inf " << inf << "\n";
                        }
                        else
                        {
                            cout << "Node Found wiht Inf " << inf << "\n";
                        }
                        break;         
            case(9) :   root = create_bt();
                        break;
            case(10) :   return 0;
        }
    }
}