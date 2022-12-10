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
    long total = 0;
    long maxp = 0;
    int maxProduct(TreeNode *root)
    {
        dfs(root);
        maxprod(root);
        return maxp % (long)(1e9 + 7);
    }
    void dfs(TreeNode *root)
    {
        if (!root)
            return;
        total += (long)(root->val);
        dfs(root->left);
        dfs(root->right);
    }
    long maxprod(TreeNode *root)
    {
        if (!root)
            return 0;
        long subSum = root->val;
        subSum += (long)maxprod(root->left);
        subSum += (long)maxprod(root->right);
        maxp = max(maxp, (subSum * (total - subSum)));
        return subSum;
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
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    Solution obj;
    TreeNode *root = new TreeNode();
    root = obj.createTree(arr, 6);
    cout << obj.maxProduct(root);

    return 0;
}