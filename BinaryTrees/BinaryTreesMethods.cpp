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

int height(BinaryTreeNode<int>* root) {
    if(root == NULL){
		return 0;
	}

	int leftHeight = height(root->left);
	int rightHeight = height(root->right);
	
	return 1 + max(leftHeight, rightHeight);
}

void mirrorBinaryTree(BinaryTreeNode<int>* root) {
   
   if(root == NULL){
	   return;
   }

   mirrorBinaryTree(root->left);
   mirrorBinaryTree(root->right);

	BinaryTreeNode<int>* temp = root->left;
	root->left = root->right;
	root->right = temp;
}

int diameter(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }

    int option1 = height(root->left) + height(root->right); //height() function described above
    int option2 = diameter(root->left);
    int option3 = diamter(root->right);

    return max(option1, max(option2, option3));
}

//better approach for diameter of binary tree
pair<int, int> heightDiameter(BinaryTreeNode<int>* root){
    if(root == NULL){
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<int, int> leftAns = heightDiameter(root->left);
    pair<int, int> rightAns = heightDiameter(root->right);

    int leftDiameter = leftAns.second;
    int leftHeight = leftAns.first;
    int rightDiameter = rightAns.second;
    int rightHeight = rightAns.first;

    int height = 1 + max(lh, rh);
    int diameter = max(leftHeight + rightHeight, max(leftDiameter, rightDiameter));
    pair<int, int> p;
    p.first = height;
    p.second = diameter;

    return p;
}

int getSum(BinaryTreeNode<int>* root) {
    if(root == NULL){
		return 0;
	}
	return root->data + getSum(root->left) + getSum(root->right);
}