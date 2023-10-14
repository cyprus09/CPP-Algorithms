#include <iostream>
#include <queue>
#include <stack>
#include "binarytree.h"
using namespace std;


int height(BinaryTreeNode<int>* root) {
    if(root == NULL){
		return 0;
	}

	int leftHeight = height(root->left);
	int rightHeight = height(root->right);
	
	return 1 + max(leftHeight, rightHeight);
}

void zigZagOrder(BinaryTreeNode<int> *root) {
    if(root == NULL){
		return;
	}

	int n = height(root);

	stack<BinaryTreeNode<int>*> s1; // fill from right --> left
	stack<BinaryTreeNode<int>*> s2; //fill from left --> right
	
	s1.push(root); 
	
	while(n >= 0){
		if(n%2 == 0){
			while (!s1.empty()) {
				BinaryTreeNode<int>* curr = s1.top();
				s1.pop();
				cout << curr->data << " ";

				if(curr->left != NULL){
					s2.push(curr->left);
				}
				if(curr->right != NULL){
					s2.push(curr->right);
				}
			}
			cout << endl;
		}else{
			while (!s2.empty()) {
				BinaryTreeNode<int>* curr = s2.top();
				s2.pop();
				cout << curr->data << " ";

				if(curr->right != NULL){
					s1.push(curr->right);
				}
				if(curr->left != NULL){
					s1.push(curr->left);
				}
			}
			cout << endl;
		}
		n--;
	}
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    zigZagOrder(root);
}