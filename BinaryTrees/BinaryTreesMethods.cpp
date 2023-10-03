#include <iostream>
#include <queue>
#include "binarytree.h"
using namespace std;

BinaryTreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout << "Enter root data: " << endl;
    cin >> rootData;
    if(rootData == -1){
        return NULL;
    }
    
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!(pendingNodes.empty())){
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        int leftData;
        cout << "Enter left child of " << front->data << endl;
        cin >> leftData;
        if(leftData != -1){
            BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(leftData);
            pendingNodes.push(leftChild);
        }

        int rightData;
        cout << "Enter right child of " << front->data << endl;
        cin >> rightData;
        if(rightData != -1){
            BinaryTreeNode<int>* rightChild = new BinaryTreeNode<int>(rightChild);
            pendingNodes.push(leftChild);
        }
    } 
    return root;
}

int numNodes(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }

    return 1 + numNodes(root->left) + numNodes(root->right);
}

//recursive method to return bool for node presence
bool isNodePresent(BinaryTreeNode<int> *root, int x) {
 if (root == NULL) {
        return false;
    }
    if (root->data == x) {
        return true;
    }

    bool isLeftPresent = isNodePresent(root->left, x);
    bool isRightPresent = isNodePresent(root->right, x);

    return isLeftPresent || isRightPresent;
}

//another method using queue to check for node presence
bool isNodePresent(BinaryTreeNode<int> *root, int x) {

    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    while(!q.empty()){
        BinaryTreeNode<int>* front = q.front();
        q.pop();
        if(front->data == x){
            return true;
        }
        if(front->left != NULL){
            q.push(front->left);
        }
        if(front->right != NULL){
            q.push(front->right);
        }
    }

    return false;
}