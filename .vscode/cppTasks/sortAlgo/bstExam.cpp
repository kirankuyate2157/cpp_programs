#include <iostream>
#include <vector>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node()
    {
        left = NULL;
        right = NULL;
    }
    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

node *insert(node *root, int x)
{
    node *temp = new node(x);
    if (root == NULL)
    {
        root = temp;
        return root;
    }
    if (x > root->data)
    {
        root->right = insert(root->right, x);
    }
    else if (x < root->data)
    {
        root->left = insert(root->left, x);
    }
    return root;
}
void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
vector<int> longPath(node *root)
{
    if (root == NULL)
    {
        vector<int> temp = {};
        return temp;
    }
    vector<int> Lside = longPath(root->left);
    vector<int> Rside = longPath(root->right);
    if (Lside.size() > Rside.size())
        Lside.push_back(root->data);
    else
        Rside.push_back(root->data);
    return (Lside.size() > Rside.size()) ? Lside : Rside;
}

bool Search(node *root, int x)
{
    if (root == NULL)
        return 0;
    if (root->data == x)
    {
        cout << "data found \n";
        return 1;
    }
    else if (root->data < x)
    {
        return Search(root->right, x);
    }
    else
    {
        return Search(root->left, x);
    }
}
int main()
{

    int arr[] = {11, 3, 12, 6, 1, 21, 78, 34, 13, 4, 5, 9, 13, 4, 5, 6, 7};
    node *root = new node(10);
    int n = sizeof(arr) / sizeof(arr[0]);
    inorder(root);
    for (int j = 0; j < n; j++)
    {
        insert(root, arr[j]);
    }
    cout << "\n";
    inorder(root);
    cout << "\n";
    vector<int> v = longPath(root);
    for (auto x : v)
        cout << x << " ";
    cout << "\n";
    cout << Search(root, 13);
    cout << "\n";
    cout << Search(root, 99);
    cout << "\n";
    cout << Search(root, 78);
    return 0;
}