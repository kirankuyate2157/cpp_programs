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
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<int> A, B;
        bs(root1, A);
        bs(root2, B);
        return A == B;
    }
    void bs(TreeNode *node, vector<int> &arr)
    {
        if (!node)
            return;
        if (!node->left && !node->right)
            arr.push_back(node->val);
        bs(node->left, arr);
        bs(node->right, arr);
    }
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
    vector<int> arr1 = {3, 5, 1, 6, 2, 9, 8, 7, 4};
    vector<int> arr2 = {3, 5, 1, 6, 7, 4, 2, 9, 8};
    Solution obj;
    TreeNode *root1 = new TreeNode();
    TreeNode *root2 = new TreeNode();
    root1 = obj.createTree(arr1, arr1.size());
    root2 = obj.createTree(arr2, arr2.size());
    cout << obj.leafSimilar(root1, root2) << endl;
    return 0;
}