#include <iostream>
#include <queue>
#include <vector>
#include "BinarySearchTree.h"

using namespace std;

void rootToLeafPathsSumToKHelper(BinaryTreeNode<int>* root, int k, vector<int>& pathValues){
    if (root == NULL) {
        return;
    }
    k = k - root->data;
    pathValues.push_back(root->data);
    if (root->left == NULL && root->right == NULL) {
        if (k == 0) {
            for (int i = 0; i < pathValues.size(); i++) {
                cout << pathValues[i] << " ";
            }
            cout << endl;
        }
    }
    rootToLeafPathsSumToKHelper(root->left, k, pathValues);
    rootToLeafPathsSumToKHelper(root->right, k, pathValues);
	pathValues.pop_back();

}

void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
   if (root == NULL) {
        return;
    }
    vector<int> ansValues;
    rootToLeafPathsSumToKHelper(root, k, ansValues);
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int k;
    cin >> k;
    rootToLeafPathsSumToK(root, k);
    delete root;
}