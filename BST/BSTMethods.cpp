#include <iostream>
#include <queue>
#include <climits>
#include "BinarySearchTree.h"

using namespace std;

//searching where a particular node is
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

//printing all elements within a given range
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

//constructing BST from an array of integers
BinaryTreeNode<int>* constructTreeHelper(int *input, int left, int right){
	if(left > right){
		return NULL;
	}
	
	int mid = left + (right - left)/2;

	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(input[mid]);
	root->left = constructTreeHelper(input, left, mid - 1);
	root->right = constructTreeHelper(input, mid + 1, right);

	return root;
}
BinaryTreeNode<int>* constructTree(int *input, int n) {
	return constructTreeHelper(input, 0, n - 1);
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