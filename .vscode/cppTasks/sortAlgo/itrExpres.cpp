/*
Experiment 5 : Construct an expression tree from the given prefix and traverse it using post order traversal and then delete the entire tree.
*/

#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    char data;
    node *left;
    node *right;
    node()
    {
        left = NULL;
        right = NULL;
    }
    node(char data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class tree
{
    stack<node *> st;

public:
    void expression(string s)
    {
        if (isOperand(s))
        {
            node *temp = new node(s);
            st.pin(temp);
        }
        else if (isOperator(s))
        {
            node *temp = new node(s);
            temp->left = st.top();
            st.pop();
            temp->right = st.top();
            st.pop();
            st.push(temp);
        }
    }
    void postOrder(node *temp)
    {
        if (temp != NULL)
        {
            postOrder(temp->left);
            postOrder(temp->right);
            cout << temp->data << " ";
        }
    }
    void itrPostOrder(node *temp)
    {
        stack<node *> s, ans;
        s.push(temp);
        while (!s.empty())
        {
            node *cur = s.top();
            s.pop();
            ans.push(cur);
            if (cur->left != NULL)
            {
                s.push(cur->left);
            }
            if (cur->right != NULL)
            {
                s.push(cur->right);
            }
        }
        while (!ans.empty())
        {
            cout << ans.top()->data << " ";
            ans.pop();
        }
    }

    bool isOperand(char x)
    {
        if ((x >= 'a' && x <= 'z') || (x >= 'A' || x >= 'Z') || (x >= '0' && x <= '9'))
            return true;
        return false;
    }
    bool isOperator(char x)
    {
        if (x == '+' || x == '-' || x == '*' || x == '/')
            return true;
        return false;
    }
};
int main()
{

    return 0;
}