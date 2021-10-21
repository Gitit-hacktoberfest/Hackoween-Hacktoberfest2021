//Given a Binary tree, find the largest BST subtree. That is, you need to find the BST with maximum height in the given binary tree. You have to return the height of largest BST.

#include<climits>
#include<cmath>
#include <iostream>
#include <queue>

template <typename T>
using namespace std;

class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode() {
        if (left) delete left;
        if (right) delete right;
    }
};


int height(BinaryTreeNode<int> *root){
    if(root == NULL){
        return 0;
    }
    int ans1 = 0; int ans2 = 0;
    
    ans1 = height(root -> left);
    ans2 = height(root -> right);
    
    if(ans1 > ans2){
        return ans1 + 1;
    }
    else{
        return ans2 + 1;
    }
    
}

bool isBST(BinaryTreeNode<int> *root, int min = INT_MIN, int max = INT_MAX){
    if(root == NULL){
        return true;
    }
    if(root -> data < min || root -> data > max){
        return false;
    }
    
    bool isLeftOK = isBST(root -> left, min, root -> data -1);
    bool isRightOK = isBST(root -> right, root -> data + 1, max);
    
    return isLeftOK && isRightOK;
}

int largestBSTSubtree(BinaryTreeNode<int> *root) {
	
    if(isBST(root)){
        return height(root);
    }
    else{
        int ans1 = largestBSTSubtree(root -> left);
        int ans2 = largestBSTSubtree(root -> right);
        
        return max(ans1, ans2);
    }
}



BinaryTreeNode<int>* takeInput() {
    int rootData;
    
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
       
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        
        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << largestBSTSubtree(root);
    delete root;
}

