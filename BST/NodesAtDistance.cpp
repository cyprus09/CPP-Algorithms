#include <iostream>
#include <queue>
#include "BinarySearchTree.h"

using namespace std;

void nodesAtDistanceKHelper(BinaryTreeNode<int>* curr, int k) {
    if (curr == NULL) {
        return;
    }
    if (k == 0) {
        cout << curr->data << endl;
    }
    nodesAtDistanceKHelper(curr->left, k - 1);
    nodesAtDistanceKHelper(curr->right, k - 1);
}

int printNodes(BinaryTreeNode<int>* curr, int node, int k) {
    if (curr == NULL) {
        return -1;
    }
    if (curr->data == node) {
        nodesAtDistanceKHelper(curr, k);
        return 0;
    }
    int leftDistance = printNodes(curr->left, node, k);
    if (leftDistance != -1) {
            if (leftDistance + 1 == k) {
                    cout << curr->data << endl;
            } else {
                    nodesAtDistanceKHelper(curr->right, k - leftDistance - 2);
            }
            return leftDistance + 1;
    }

    int rightDistance = printNodes(curr->right, node, k);
    if (rightDistance != -1) {
            if (rightDistance + 1 == k) {
                    cout << curr->data << endl;
            } else {
                    nodesAtDistanceKHelper(curr->left, k - rightDistance - 2);
            }
            return rightDistance + 1;
    }
    return -1;
}

void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
    if(root == NULL){
            return;
    }
    printNodes(root, node, k);
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int targetNode, k;
    cin >> targetNode >> k;
    nodesAtDistanceK(root, targetNode, k);
    delete root;
}