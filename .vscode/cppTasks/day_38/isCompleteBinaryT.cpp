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
    bool isCompleteTree(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *node = q.front();
            cout << q.front() << ", ";
            q.pop();
            if (node)
            {
                // add nodes all at leaf position when you face Null then it ok is satifying complete tree...
                // but if in the queue stil non-null node is there  then it`s not satifying condition so it will be false
                q.push(node->left);
                q.push(node->right);
            }
            else
            {
                while (!q.empty())
                {
                    cout << q.front() << ", ";
                    if (q.front())
                        return false;
                    q.pop();
                }
            }
        }
        return true;
    }
};
int main()
{
    // Input: root = [1,2,3,4,5,6]
    // Output: true
    // Explanation: Every level before the last is full (ie. levels with node-values {1} and {2, 3}), and all nodes in the last level ({4, 5, 6}) are as far left as possible.
    return 0;
}