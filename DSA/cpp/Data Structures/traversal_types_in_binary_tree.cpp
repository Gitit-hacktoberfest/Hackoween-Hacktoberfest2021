/* Implement Preorder, Inorder and Postorder traversal operations. Traverse the tree given in the example below.
  Tree:                      
                             60
                          //    \\
                         //      \\
                        //        \\
                      70           90
                    //  \\           \\
                   //    \\           \\
                  20      55           88
                 //
                //
               28
               
Expected output:
PREORDER:   60 -> 70 -> 20 -> 28 -> 55 -> 90 -> 88
INORDER:    28 -> 20 -> 70 -> 55 -> 60 -> 90 -> 88
POSTORDER:  28 -> 20 -> 55 -> 70 -> 88 -> 90 -> 60
               
*/
#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* left, *right;
};


Node* rooti(int data) {

    Node* root = new Node();
    root->left = root->right = NULL;
    root->value = data;
    return root;
}

Node* addNode(int data) {
    Node* node = new Node;
    node->value = data;
    node->left = node->right = NULL;
    return node;
}


void printer(int i, Node* root) {
    if (!root)
        return;
    switch(i) {
        case 1:

            cout<<root->value<<" -> ";
            printer(i, root->left);
            printer(i, root->right);
            break;

        case 2:

            printer(i, root->left);
            cout<<root->value<<" -> ";
            printer(i, root->right);
            break;

        case 3:

            printer(i, root->left);
            printer(i, root->right);
            cout<<root->value<<" -> ";
            break;
    }
}

int main() {
    Node* root = rooti(60);

    root->left = addNode(70);
    root->right = addNode(90);

    root->left->left = addNode(20);
    root->left->right = addNode(55);

    root->right->right = addNode(88);

    root->left->left->left = addNode(28);
    cout<<"20BPS1060 SHANTANU\n\n";
    cout<<"PREORDER :\t";
    printer(1, root);
    cout<<"\n\n";

    cout<<"INORDER :\t";
    printer(2, root);
    cout<<"\n\n";

    cout<<"POSTORDER :\t";
    printer(3, root);
    cout<<"\n\n";


    return 0;
}
