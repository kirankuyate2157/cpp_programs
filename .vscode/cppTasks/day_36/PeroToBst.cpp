#include <bits/stdc++.h>
using namespace std;
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
    TreeNode *helper(vector<int> arr, int l, int r)
    {
        if (l >= r)
            return NULL;
        int val = arr[l];
        TreeNode *root = new TreeNode(val);
        int x = l + 1;
        while (l <= arr.size() && arr[x] < val)
        {
            x++;
        }
        root->left = helper(arr, l + 1, x);
        root->right = helper(arr, x, r);
        return root;
    }
    void print(TreeNode *root)
    {
        if (!root)
            return;
        print(root->left);
        cout << root->val << ", ";
        print(root->right);
    }
};
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    Solution obj;
    TreeNode *root = obj.helper(arr, 0, arr.size());
    obj.print(root);
    return 0;
}