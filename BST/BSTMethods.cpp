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

//path to a particular node
vector<int>* getPath(BinaryTreeNode<int> *root , int data) {
	if(root == NULL){
		return NULL;
	}

	if(root->data == data){
		vector<int>* output = new vector<int>();
		output->push_back(root->data);
		return output;
	}

	vector<int>* leftOutput = getPath(root->left, data);

	if(leftOutput != NULL){
		leftOutput->push_back(root->data);
		return leftOutput;
	}

	vector<int>* rightOutput = getPath(root->right, data);
	if(rightOutput != NULL){
		rightOutput->push_back(root->data);
		return rightOutput;
	}else{
		return NULL;
	}
	
}

//get lowest common ancestor (lowest - most depth)
int getLCA(BinaryTreeNode<int>* root , int val1 , int val2){
    if(root == NULL){
		return -1;
	}
	if(root->data == val1 || root->data == val2){
		return root->data;
	}
	int temp1 = getLCA(root->left, val1, val2);
	int temp2 = getLCA(root->right, val1, val2);

	if(temp1 != -1 && temp2 == -1){
		return temp1;
	}
	if(temp1 == -1 && temp2 != -1){
		return temp2;
	}
	if(temp1 != -1 && temp2 != -1){
		return root->data;
	}
	if(temp1 == -1 && temp2 == -1){
		return -1;
	}
}

int replaceWithLargerNodesSumHelper(BinaryTreeNode<int>* root, int sum){
	if(root == NULL){
		return sum;
	}
	sum = replaceWithLargerNodesSumHelper(root->right, sum);
	sum += root->data;
	root->data = sum;
	sum = replaceWithLargerNodesSumHelper(root->left, sum);

	return sum;
}

void replaceWithLargerNodesSum(BinaryTreeNode<int> *root) {
    replaceWithLargerNodesSumHelper(root, 0);
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