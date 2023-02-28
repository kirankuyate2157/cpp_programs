#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        vector<TreeNode *> ans;
        unordered_map<string, int> count;
        encode(root, count, ans);
        return ans;
    }

private:
    string encode(TreeNode *root, unordered_map<string, int> &count,
                  vector<TreeNode *> &ans)
    {
        if (root == nullptr)
            return "";

        const string encoded = to_string(root->val) + "#" +
                               encode(root->left, count, ans) + "#" +
                               encode(root->right, count, ans);
        // # for encoding null left and right childs
        if (++count[encoded] == 2) // duplicate subtree
            ans.push_back(root);   // add the roots
        return encoded;
    }
};
int main()
{

    return 0;
}