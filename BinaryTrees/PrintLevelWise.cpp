#include <iostream>
#include <queue>
#include "binarytree.h"
using namespace std;

//take input generally
BinaryTreeNode<int>* takeInput(){
    int rootData;
    cout << "Enter Data: " << endl;
    cin >> rootData;
    if(rootData == -1){
        return NULL;
    }
    
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    
    BinaryTreeNode<int> *leftChild = takeInput();
    root->left = leftChild;
    BinaryTreeNode<int> *rightChild = takeInput();
    root->right = rightChild;

    return root;
}

//take input level-wise (depth-wise)
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

//printing nodes according to depth
void printTree(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
    cout << root->data << ": ";
    if(root->left->data != -1){
        cout << "L" << root->left->data << ",";
    }
    if(root->right->data != -1){
        cout << "R" << root->left->data;
    }
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}

//printing nodes level-wise (by depth)
void printLevelWise(BinaryTreeNode<int> *root) {
	if(root == NULL){
		return;
	}

	queue<BinaryTreeNode<int>*> q;
	q.push(root);

	while(!(q.empty())){

    	BinaryTreeNode<int> *front = q.front();
    	q.pop();

		cout << front->data << ":";

		if(front->left != NULL){
        	cout << "L:" << front->left->data;
			q.push(front->left);
    	}else{
			cout << "L:" << -1;
		}
    	if(front->right != NULL){
        	cout << ",R:" << front->right->data;
			q.push(front->right);
    	}else{
			cout << ",R:" << -1;
		}

		cout << endl;
	}
}

int main() {
    BinaryTreeNode<int>* root = takeInputLevelWise();
    printLevelWise(root);
}