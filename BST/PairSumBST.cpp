#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include "BinarySearchTree.h"

using namespace std;

void preOrder(BinaryTreeNode<int>* root, vector<int>& nodeValues){
	if(root == NULL){
		return;
	}
	nodeValues.push_back(root->data);
	preOrder(root->left, nodeValues);
	preOrder(root->right, nodeValues);
}

void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
    if(root == NULL){
		return;
	}
	
	vector <int> resultValues;
	preOrder(root, resultValues);
	sort(resultValues.begin(), resultValues.end());

	int left = 0;
	int right = resultValues.size() - 1;
	while(left < right){
		int currentSum = resultValues[left] + resultValues[right];
		if(currentSum == s){
			cout << resultValues[left] << " " << resultValues[right] << endl;
			left++;
			right--;
		}
		if(currentSum < s){
			left++;
		}
		if(currentSum > s){
			right--;
		}
	}
}

int main() {
    BinaryTreeNode<int> *root = takeInput();
    int s;
    cin >> s;
    printNodesSumToS(root, s);
    delete root;
}