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
    int sum = INT_MIN;

    int maxPathSum(TreeNode *root)
    {
        if (!root)
            return 0;
        givemax(root);
        return sum;
    }
    int givemax(TreeNode *root)
    {
        if (!root)
            return 0;

        int l = givemax(root->left);
        int r = givemax(root->right);
        int sum1 = max(root->val, max(root->val + l, max(root->val + r, root->val + l + r)));
        if (sum1 > sum)
            sum = sum1;
        cout << sum << " ";
        return root->val > root->val + max(l, r) ? root->val : root->val + max(l, r);
    }
};

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    Solution obj;
    TreeNode *root = new TreeNode();
    root = obj.createTree(arr, 6);

    cout << "max path sum is :" << obj.maxPathSum(root) << endl;
    return 0;
}
