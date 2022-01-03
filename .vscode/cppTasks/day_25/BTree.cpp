#include <bits/stdtr1c++.h>
using namespace std;

class tree
{
public:
    int data;
    tree *left;
    tree *right;

    tree(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
void inorder(tree *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(tree *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    inorder(root->left);
    inorder(root->right);
}
void postorder(tree *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    inorder(root->right);
    cout << root->data << " ";
}

void itrInorder(tree *root)
{
    stack<pair<tree *, int>> st;
    st.push({root, 0});
    while (!st.empty())
    {
        tree *cur = st.top().first;
        int state = st.top().second;
        st.pop();
        if (cur == NULL)
        {
            continue;
        }
        if (state == 0)
        {
            // cout << cur->data << " ";
            st.push({cur, 1});
            st.push({cur->left, 0});
        }
        else if (state == 1)
        {
            cout << cur->data << " ";
            st.push({cur, 2});
        }
        else
        {

            st.push({cur->right, 0});
        }
    }
}

void insrt(tree *&root, int x)
{
    tree *temp = new tree(x);
    if (root == NULL)
    {
        root = temp;
        return;
    }
    else if (temp <= root)
    {
        insrt(root->left, x);
    }
    else
    {
        insrt(root->right, x);
    }
}

tree *mirror(tree *&root)
{
    if (root == NULL)
    {
        return root;
    }
    tree *leftside = root->left;
    tree *rightside = root->right;
    root->left = mirror(rightside);
    root->right = mirror(leftside);
    return root;
}

int height(tree *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return max(height(root->left), height(root->right)) + 1;
}

int diamiter(tree *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int tl = diamiter(root->left);
    int tr = diamiter(root->right);
    int mydi = max(height(root->left), height(root->right)) + 1;
    return max(max(tl, tr), mydi);
}

vector<int> revOrdTravers(tree *root)
{
    vector<int> ans;
    queue<tree *> q;
    q.push(root);
    while (!q.empty())
    {
        tree *cur = q.front();
        q.pop();
        ans.push_back(cur->data);
        if (root->right != NULL)
        {
            q.push(root->right);
        }
        if (root->left != NULL)
        {
            q.push(root->left);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

vector<int> diagonal(Node *root)
{
    vector<int> ans;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *cur = q.front();
        q.pop();
        ans.push_back(cur->data);
        while (cur->right != NULL)
        {
            ans.push_back(cur->right->data);

            if (cur->left != NULL)
            {
                q.push(cur->left);
            }
            cur = cur->right;
        }
    }
    return ans;
}

vector<int> topview(tree *root)
{
    vector<int> ans;
    map<int, int> m;
    queue<pair<tree *, int>> q;
    int level = 0

                q.push(root, 0);
    while (!q.empty())
    {
        pair<tree *, int> cur = q.front();
        q.pop();
        ans.push_back(cur.first->data);
        if (root->right != NULL)
        {
            level++;
            q.push(root->right, level++);
        }
        if (root->left != NULL)
        {
            level--;
            q.push(root->left, level--);
        }
    }
}

int main()
{
    int t;
    // cin >> t;
    tree *root = new tree(10);
    int x;
    root->left = new tree(4);
    root->right = new tree(12);
    root->left->right = new tree(8);
    root->right->right = new tree(25);
    root->left->right->left = new tree(7);
    root->left->left = new tree(1);

    // while (t--)
    // {
    //     cin >> x;

    //     insrt(root, x);
    // }
    inorder(root);
    mirror(root);
    cout << "\n";
    cout << "diameter of tree  : " << diamiter(root) << "\n";
    inorder(root);
    cout << "\n";
    vector<int> r = revOrdTravers(root);
    for (int i = 0; i < r.size(); i++)
    {

        cout << r[i] << ",";
    }
    return 0;
}