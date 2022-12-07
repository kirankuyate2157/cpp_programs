#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        if (!root || low > high)
            return 0;
        if (root->val < low)
            return rangeSumBST(root->right, low, high);
        if (root->val > high)
            return rangeSumBST(root->left, low, high);
        return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }

    void bs(TreeNode *root, int low, int high, vector<int> &ans)
    {
        if (root == NULL)
            return;
        if (root->val >= low && root->val <= high)
        {
            ans.push_back(root->val);
        }
        // cout<<root->val<<" ";
        bs(root->left, low, high, ans);
        bs(root->right, low, high, ans);
    }
    void makeTree(TreeNode *root, int x)
    {
        TreeNode *temp = new TreeNode(x);
        if (root == NULL)
        {
            root = temp;
            return;
        }
        if (x <= root->val)
            makeTree(root->left, x);
        else
            makeTree(root->right, x);
    }
    // Both the children of this new TreeNode are initially null.
    TreeNode *insertValue(TreeNode *root, int value, queue<TreeNode *> &q)
    {
        TreeNode *node = new TreeNode(value);
        if (root == NULL)
            root = node;
        else if (q.front()->left == NULL)
            q.front()->left = node;

        else
        {
            q.front()->right = node;
            q.pop();
        }
        q.push(node);
        return root;
    }
    TreeNode *createTree(vector<int> arr, int n)
    {
        TreeNode *root = NULL;
        queue<TreeNode *> q;
        for (int i = 0; i < n; i++)
            root = insertValue(root, arr[i], q);
        return root;
    }
};
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    Solution obj;
    TreeNode *root = new TreeNode();
    root = obj.createTree(arr, 6);

    cout << "Range sum  is :" << obj.rangeSumBST(root, 1, 6);
}