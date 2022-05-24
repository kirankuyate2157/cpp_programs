#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left = NULL;
    node *right = NULL;
    node(int data)
    {
        this->data = data;
    }
};

// class bst
// {
//     node *temp;

// public:
//     node *root;
//     bst()
//     {
//         root = NULL;
//     }
//     bst(int data)
//     {
//         root->data = data;
//         root->left = NULL;
//         root->right = NULL;
//     }
node *newNode(int data)
{
    node *ptr = new node(data);
    return ptr;
}
node *insert(node *temp, int x)
{

    if (temp == NULL)
    {
        cout << "done" << endl;
        return temp = newNode(x);
    }
    else if (temp->data < x)
    {
        temp->right = insert(temp->right, x);
    }
    else
    {
        temp->left = insert(temp->left, x);
    }
    return temp;
}

void input(node *temp)
{
    cout << "enter no of nodes : ";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        insert(temp, ele);
    }
}
int search(node *temp, int x)
{
    if (temp == NULL)
    {
        return 0;
    }
    else
    {
        if (temp->data == x)
        {
            cout << "data is found !\n";
            return 1;
        }
        else if (temp->data < x)
        {
            return search(temp->right, x);
        }
        else
        {
            return search(temp->left, x);
        }
    }
}
node *precc(node *temp)
{
    if (temp != NULL)
    {
        while (temp->right != NULL)
        {
            temp = temp->right;
        }
    }
    return temp;
}
node *deleteNode(node *ptr, int x)
{
    if (ptr == NULL)
        return ptr;
    if (x < ptr->data)
        ptr->left = deleteNode(ptr->left, x);
    else if (x > ptr->data)
        ptr->right = deleteNode(ptr->right, x);
    else
    {
        if (ptr->right == NULL && ptr->left == NULL)
            return NULL;
        else if (!ptr->left)
            return ptr->right;
        else if (!ptr->right)
            return ptr->left;
        else
        {
            node *temp = precc(ptr);
            swap(temp->data, ptr->data);
            ptr->left = deleteNode(ptr->left, x);
        }
    }
    return ptr;
}
int depth(node *temp)
{
    if (temp != NULL)
    {
        return (max(depth(temp->left), depth(temp->right)) + 1);
    }
    return 0;
}

void mirror(node *temp)
{
    if (temp != NULL)
    {
        mirror(temp->left);
        mirror(temp->right);
        node *ptr = temp->left;
        temp->left = temp->right;
        temp->right = ptr;
    }
    else
    {
        return;
    }
}
void preorder(node *temp)
{
    if (temp != NULL)
    {
        cout << temp->data << " ";
        preorder(temp->left);
        preorder(temp->right);
    }
}
void inorder(node *temp)
{
    if (temp != NULL)
    {
        inorder(temp->left);
        cout << temp->data << " ";
        inorder(temp->right);
    }
}
void postorder(node *temp)
{
    if (temp != NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        cout << temp->data << " ";
    }
}
int minValue(node *temp)
{
    if (temp != NULL)
    {
        while (temp->left != NULL)
        {
            temp = temp->left;
        }
        return temp->data;
    }
    else
    {

        return INT_MAX;
    }
}
int maxValue(node *temp)
{
    if (temp != NULL)
    {
        while (temp->right != NULL)
        {
            temp = temp->right;
        }
        return temp->data;
    }
    else
    {
        return INT_MIN;
    }
}
// };

int main()
{
    node *root = new node(7);
    inorder(root);
    cout << "depth :" << depth(root);
    input(root);
    cout << "\n";
    inorder(root);
    cout << "\n";
    preorder(root);
    cout << "\n";
    postorder(root);
    cout << "\n";
    mirror(root);

    inorder(root);
    cout << "\n";
    cout << "max value :" << maxValue(root);
    cout << "\n";
    cout << "min value :" << minValue(root);
    cout << "\ndepth :" << depth(root);
    cout << "\n";
    cout << search(root, 10);
    deleteNode(root, 10);
    inorder(root);
    return 0;
}