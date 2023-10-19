#include <iostream>
#include <queue>
#include <climits>
#include "BinarySearchTree.h"

using namespace std;

bool searchInBST(BinaryTreeNode<int> *root , int k) {

	bool flag = false;
	if(root == NULL){
		return flag;
	}

	if(root->data == k){
		return !flag;
	}else if(k > root->data){
		return searchInBST(root->right, k);
	}else{
		return searchInBST(root->left, k);
	}
}

void elementsInRangeK1K2(BinaryTreeNode<int>* root, int k1, int k2) {
	if(root == NULL){
		return;
	}	

	if(k1 < root->data && k2 < root->data){
		elementsInRangeK1K2(root->left, k1, k2);
	}
	if(k1 > root->data && k2 > root->data){
		elementsInRangeK1K2(root->right, k1, k2);
	}
	if(k1 <= root->data && k2 >= root->data){
		elementsInRangeK1K2(root->left, k1, k2);
		cout << root->data << " ";
		elementsInRangeK1K2(root->right, k1, k2);
	}
}

bool isBSTUtil(BinaryTreeNode<int>* root, int minVal, int maxVal) {
    if (root == NULL) {
        return true; 
    }

    if (root->data < minVal || root->data > maxVal) {
        return false;
    }

    return isBSTUtil(root->left, minVal, root->data - 1) &&
		isBSTUtil(root->right, root->data + 1, maxVal);
}

bool isBST(BinaryTreeNode<int>* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main() {
    BinaryTreeNode<int> *root = takeInput();
    int k;
    cin >> k;
    cout << ((searchInBST(root, k)) ? "true" : "false");

	int k1, k2;
    cin >> k1 >> k2;
    elementsInRangeK1K2(root, k1, k2);
	delete root;
}