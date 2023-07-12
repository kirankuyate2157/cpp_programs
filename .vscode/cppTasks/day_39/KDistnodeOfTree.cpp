/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    /*
    make parentarray store relation child->parent
    then take queue use bfs approch to traverse the  levele by level
     take queue size for level and explore all then next level
     take visisted set,or array bucket
     once visited add it to visited
     in betweeen check the level or K size if it matches to thes asked K level then stope and return  the Ansewers..

     2*n (O) time complexity
    */
    map<TreeNode *, TreeNode *> parent;

    void inorder(TreeNode *root)
    {
        if (!root)
            return;
        if (root->left)
            parent[root->left] = root;
        inorder(root->left);
        if (root->right)
            parent[root->right] = root;
        inorder(root->right);
    }

    void bfs(TreeNode *target, vector<int> &ans, int k)
    {
        queue<TreeNode *> q;
        q.push(target);

        unordered_set<int> st;
        st.insert(target->val);

        while (!q.empty())
        {
            int n = q.size();
            if (k == 0)
                break;

            while (n--)
            {
                TreeNode *temp = q.front();
                q.pop();
                if (temp->left != NULL && !st.count(temp->left->val))
                {
                    q.push(temp->left);
                    st.insert(temp->left->val);
                }
                if (temp->right != NULL && !st.count(temp->right->val))
                {
                    q.push(temp->right);
                    st.insert(temp->right->val);
                }
                if (parent.count(temp) && !st.count(parent[temp]->val))
                {
                    q.push(parent[temp]);
                    st.insert(parent[temp]->val);
                }
            }
            k--;
        }
        while (!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
    }
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        vector<int> ans;
        inorder(root);

        bfs(target, ans, k);
        return ans;
    }
};