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

TreeNode *createBST(vector<int> &root)
{
    if (root.size() == 0)
    {
        return nullptr;
    }
    TreeNode *rootNode = new TreeNode(root[0]);
    for (int i = 1; i < root.size(); i++)
    {
        // if (root[i] != NULL)
        // {
        TreeNode *newNode = new TreeNode(root[i]);
        TreeNode *currNode = rootNode;
        while (currNode != nullptr)
        {
            if (newNode->val < currNode->val)
            {
                if (currNode->left == nullptr)
                {
                    currNode->left = newNode;
                    break;
                }
                else
                {
                    currNode = currNode->left;
                }
            }
            else
            {
                if (currNode->right == nullptr)
                {
                    currNode->right = newNode;
                    break;
                }
                else
                {
                    currNode = currNode->right;
                }
            }
        }
    }

    return rootNode;
}

class Solution
{
public:
    int ans = INT_MAX;
    int minDiffInBST(TreeNode *root)
    {
        if (!root)
            return 0;
        inorder(root);
        return ans;
    }
    int pre = -1;
    void inorder(TreeNode *root)
    {
        if (!root)
            return;
        inorder(root->left);
        // cout << root->val << "->";
        if (pre >= 0)
            ans = min(ans, (root->val - pre));
        pre = root->val;
        inorder(root->right);
    }
};
int main()
{
    vector<int> nodes = {1, 0, 48, 12, 49};
    TreeNode *root = createBST(nodes);
    cout << root->val << ": ";
    Solution obj;
    cout << "min Diff is : " << obj.minDiffInBST(root);
    return 0;
}