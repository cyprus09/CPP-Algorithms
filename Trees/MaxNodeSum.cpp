#include <vector>
#include <queue>
#include <iostream>
#include "TreesClass.h"
using namespace std;

TreeNode<int>* maxSumNode(TreeNode<int>* root) {
        if (root == NULL) {
        return NULL;
    }
    
    int sum = root->data;
    for (int i = 0; i < root->children.size(); i++) {
        sum += root->children[i]->data;
    }

    TreeNode<int>* maxNode = root;

    for (int i = 0; i < root->children.size(); i++) {
        TreeNode<int>* curr = maxSumNode(root->children[i]);
        int currSum = curr->data;

        for (int j = 0; j < curr->children.size(); j++) {
            currSum += curr->children[j]->data;
        }

        if (currSum > sum) {
            sum = currSum;
            maxNode = curr;
        }
    }

    return maxNode;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();

    TreeNode<int>* ans = maxSumNode(root);

    if (ans != NULL) {
        cout << ans->data;
    }
}