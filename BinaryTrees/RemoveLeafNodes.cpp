#include <iostream>
#include <queue>
#include <cmath>
#include "binarytree.h"

using namespace std;

//queue approach
BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int> *root) {
    if (root == NULL) {
        return NULL;
    }

    queue<BinaryTreeNode<int>*> nodesQueue;
    nodesQueue.push(root);

    while (!nodesQueue.empty()) {
        BinaryTreeNode<int>* curr = nodesQueue.front();
        nodesQueue.pop();

        if (curr->left != NULL) {
            if (curr->left->left == NULL && curr->left->right == NULL) {
                delete curr->left;
                curr->left = NULL;
            } else {
                nodesQueue.push(curr->left);
            }
        }

        if (curr->right != NULL) {
            if (curr->right->left == NULL && curr->right->right == NULL) {
                delete curr->right;
                curr->right = NULL;
            } else {
                nodesQueue.push(curr->right);
            }
        }
    }

    return root;
}

//recursive approach
BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int> *root) {
    if (root == NULL) {
        return NULL;
    }

    if(root->left == NULL && root->right == NULL){
		delete root;
		return NULL;
	}

	root->left = removeLeafNodes(root->left);
	root->right = removeLeafNodes(root->right);

    return root;
}

void printLevelATNewLine(BinaryTreeNode<int>* root) {
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        BinaryTreeNode<int>* first = q.front();
        q.pop();
        if (first == NULL) {
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL) {
            q.push(first->left);
        }
        if (first->right != NULL) {
            q.push(first->right);
        }
    }
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    root = removeLeafNodes(root);
    printLevelATNewLine(root);
}

