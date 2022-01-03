#include <iostream>
using namespace std;
class tree
{
public:
    int data;
    tree *left;
    tree *right;
    tree(int x)
    {
        data = x;
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
    cout << root->data<<",";
    inorder(root->right);
}
void preorder(tree* root){
if(root==NULL){
    return ;
}
cout<<root->data<<",";
preorder(root->left);
preorder(root->right);

}
void postorder(tree* root){
if(root==NULL){
    return ;
}
postorder(root->left);
postorder(root->right);
cout<<root->data<<",";

}

int main()
{
    tree *t = new tree(7);
    t->left=new tree(5);
    t->right=new tree(9);
    t->left->left=new tree(4);
    t->left->right=new tree(6);
    t->right->left=new tree(8);
    t->left->right=new tree(10);
    cout << t->data << "\n";
    cout << "inorder traversal .....\n";
    inorder(t);
        cout << "\n-------inorder traversal .....\n";
    preorder(t);
     cout << "\n-------post order traversal .....\n";
     postorder(t);
    return 0;
}