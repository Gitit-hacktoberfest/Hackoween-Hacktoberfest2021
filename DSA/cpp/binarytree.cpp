#include <iostream>
using namespace std;

struct node
{
  int key;
  node*left;
  node*right;
  node(int k)
  {
    key = k;
    left = NULL;
    right = NULL; 
  }
};
void inorder(node*k)
{
  if(k!= NULL)
  {
    inorder(k->left);
    cout << k->key <<" ";
    inorder(k->right);
  }
}
void preorder(node*k)
{
  if(k!= NULL)
  {
    cout << k->key << " ";
    preorder(k->left);
    preorder(k->right);
  }
}
void postorder(node*k)
{
  if(k!= NULL)
  {
    postorder(k->left);
    postorder(k->right);
    cout << k->key <<" ";
  }
}
int main() {
  node*root = new node(10);
  root->left = new node(20);
  root->right = new node(30);
  root->left->left = new node(40);
  inorder(root);
  cout<<endl;
  preorder(root);
  cout<<endl;
  postorder(root);
  cout<<endl;
}
