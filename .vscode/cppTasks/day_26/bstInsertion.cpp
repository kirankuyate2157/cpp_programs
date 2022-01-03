#include <bits/stdc++.h>
using namespace std;
class BST
{
public:
    int data;
    BST *left, *right;
    BST()
    {
        data = 0;
        left = right = NULL;
    }
    BST(int data)
    {
        this->data = data;
        left = right = NULL;
    }
    BST *insert(BST *root, int value)
    {
        if (!root)
        {
            return new BST(value);
        }
        if (value > root->data)
        {
            root->right = insert(root->right, value);
        }
        else
        {
            root->left = insert(root->left, value);
        }
        return root;
    }
    void inorder(BST *root)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left);
        cout << root->data << ",";
        inorder(root->right);
    }
    bool ispresent(BST *root, int x)
    {
        if (root == NULL)
        {
            return false;
        }
        if (root->data == x)
        {
            return true;
        }
        if (x < root->data)
            ispresent(root->left, x);
        else
            ispresent(root->right, x);
    }

    BST *constructTree(int arr[], int &ptrInd, int x, int low, int high, int size)
    {
        if (ptrInd >= size)
        {
            return NULL;
        }
        if (x < high && x > low)
        {
            BST *root = new BST(x);
            ptrInd++;
            if (ptrInd < size)
            {
                root->left = constructTree(arr, ptrInd, arr[ptrInd], INT_MIN, x, size);
            }
            if (ptrInd < size)
            {
                root->left = constructTree(arr, ptrInd, arr[ptrInd], x, INT_MAX, size);
            }
            return root;
        }
    }

        BST *buildTree(int arr[], int n)
        {
            int ptrInd = 0;
            return constructTree(arr, ptrInd, arr[ptrInd], INT_MIN, INT_MAX, n);
        }
    };

    void insert(BST *&root, int key)
    {
        if (root == NULL)
        {
            root = new BST(key);
            return;
        }
        if (root->data == key)
        {
            return;
        }
        if (key < root->data)
        {
            insert(root->left, key);
        }
        else
        {
            insert(root->right, key);
        }
    }

    BST *precc(BST *root)
    {
        BST *temp = root->left;
        while (temp->right)
        {
            temp = temp->right;
        }
        return temp;
    }
    BST *deleteNode(BST *&root, int x)
    {
        if (root == NULL)
            return root;
        if (x < root->data)
            root->left = deleteNode(root->left, x);
        else if (x > root->data)
            root->right = deleteNode(root->right, x);
        else
        {
            if (root->right == NULL && root->left == NULL)
                return NULL;
            else if (!root->left)
                return root->right;
            else if (!root->right)
                return root->left;
            else
            {
                BST *temp = precc(root);
                swap(temp->data, root->data);
                root->left = deleteNode(root->left, x);
            }
        }
        return root;
    }
    int main()
    {
        int arr[] = {34, 56, 12, 78, 9012, 34, 5, 6, 55, 23, 55, 12, 3, 98, 12, 34, 88};
        int n = sizeof(arr) / sizeof(int);
        BST b, *root = new BST(70);
        for (int x : arr)
        {
            b.insert(root, x);
        }
        // insert(root, 30);
        cout << "\n";
        b.inorder(root);
        for (int x : arr)
        {
            deleteNode(root, x);
            cout << "\n";
            b.inorder(root);
        }
        cout << "\nthe new builded tree is --->\n";
        BST N;
        BST *center = N.buildTree(arr, n);
        N.inorder(center);
        // b.ispresent(root, 12) ? cout << " \nTrue" : cout << "\n False";
        return 0;
    }