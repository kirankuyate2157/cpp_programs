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
    TreeNode *creatTree(vector<int> arr)
    {
        if (!arr.size())
            return NULL;
        TreeNode *rootNode = new TreeNode(arr[0]);
        for (int i = 1; i < arr.size(); i++)
        {
            TreeNode *newNode = new TreeNode(arr[i]);
            TreeNode *cur = rootNode;
            while (cur != NULL)
            {
                if (cur->val > newNode->val)
                {
                    if (cur->left == NULL)
                    {
                        cur->left = newNode;
                        break;
                    }
                    else
                        cur = cur->left;
                }
                else
                {
                    if (cur->right == NULL)
                    {
                        cur->right = newNode;
                        break;
                    }
                    else
                        cur = cur->right;
                }
            }
        }
        return rootNode;
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        queue<TreeNode *> q;
        if (root)
            q.push(root);
        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                TreeNode *cur = q.front();
                temp.push_back(cur->val);
                q.pop();
                if (cur->right)
                    q.push(cur->right);
                if (cur->left)
                    q.push(cur->left);
            }
            ans.push_back(temp);
            temp.clear();
        }
        for (int i = 0; i < ans.size(); i++)
        {
            if (i % 2 == 0)
            {
                reverse(ans[i].begin(), ans[i].end());
            }
        }
        return ans;
    }
};

// [[3],[20,9],[15,21],[25,18,14,12],[44]]

int main()
{

    vector<int> Nodes = {3, 9, 20, 15, 7};
    Solution obj;
    TreeNode *root = obj.creatTree(Nodes);
    vector<vector<int>> res = obj.zigzagLevelOrder(root);
    cout << "[";
    for (int i = 0; i < res.size(); i++)
    {
        cout << "[";
        for (auto x : res[i])
        {
            cout << x << " ";
        }
        cout << "]";
    }
    cout << "]";
}