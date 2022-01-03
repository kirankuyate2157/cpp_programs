#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
    Node()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }
};

class AT
{
    Node *root;
    int size;

public:
    AT()
    {
        root = NULL;
        size = 0;
    }
    void insert(int x)
    {
        root = inserthelper(root, x);
        size++;
    }
    int height(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        return max(height(root->left), height(root->right)) + 1;
    }
    Node *inserthelper(Node *root, int data)
    {
        if (root == NULL)
        {
            return new Node(data);
        }
        if (root->data < data)
        {
            root->right = inserthelper(root->right, data);
        }
        else
        {
            root->left = inserthelper(root->left, data);
        }
        int lh = height(root->left);
        int rh = height(root->right);
        if (lh - rh < -1)//i.e., right trre height is greater 
        {
            if (root->right->data > data)
            { // RR rotation
                return RR(root, root->right);
            }
            else
            { // RL rotation
                return RL(root, root->right);
            }
        }
        else if ((lh - rh) > 1)//i.r., left tree height greater
        {
            if (root->left->data < data)
            { // LR rotation
                return LR(root, root->left);
            }
            else
            {
                // LL rotation
                return LL(root, root->left);
            }
        }
        return root;
    }
    Node *RR(Node *x, Node *y)
    {
        Node *YL = y->left;
        y->left = x;
        x->right = YL;
        return y;
    }
    Node *RL(Node *x, Node *y)
    {
        Node *YL = y->left;
        Node *YLR = YL->right;
        y->left = YLR;
        x->right = YL;
        YL->right = y;
        return RR(x, YL);
    }

    Node *LL(Node *x, Node *y)
    {
        Node *YR = y->right;
        y->right = x;
        x->left = YR;
        return y;
    }

    Node *LR(Node *x, Node *y)
    {
        Node *YR = y->right;
        Node *YRL = YR->left;
        x->left = YR;
        YR->left = y;
        y->right = YRL;
        return LL(x, YR);
    }

    int Tsize()
    {
        cout << size << "\n";
        return size;
    }

    void inorder()
    {
        inorder(root);
        cout << "\n";
    }

    void inorder(Node *root)
    {
        if (root == NULL)
            return;
        cout << root->data << ",";
        inorder(root->left);
        inorder(root->right);
    }
};

int main()
{
    AT a;
    a.insert(3);
    a.inorder();
    a.insert(9);
    a.inorder();
    a.insert(3);
    a.inorder();
    a.insert(1);
    a.inorder();
    a.insert(9);
    a.inorder();
    a.insert(2);
    a.inorder();
    a.insert(88);
    a.inorder();
    a.Tsize();
    return 0;
}