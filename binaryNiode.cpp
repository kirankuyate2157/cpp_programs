#include<bits/stdc++.h>
using namespace std;
struct treeNode{
    int data;
    treeNode* left;
    treeNode* right;

};
treeNode* displaytNode(treeNode* root){
  if(root->data==NULL){
      return;
  }  
  while(root->data!=NULL){
      cout<<root->left->data;
        cout<<root->right->data;
     displaytNode(root->left);
     displaytNode(root->right);

  }
}
int main() 
{
    treeNode* root=new treeNode();
    root->data=1;
    root->left =new treeNode();
    root->left->data=2;
    root->right =new treeNode();
    root->right->data=3;
    displaytNode(root);


return 0;
}