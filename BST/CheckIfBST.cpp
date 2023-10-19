#include <iostream>
#include <queue>
#include <climits>
#include "BinarySearchTree.h"

using namespace std;

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

//another minMax method from left and right tree
int maximum(BinaryTreeNode<int>* root){
    if(root == NULL){
        return INT_MIN;
    }

    return max(root->data, max(maximum(root->left), maximum(root->right)));
}

int minimum(BinaryTreeNode<int>* root){
    if(root == NULL){
        return INT_MAX;
    }

    return min(root->data, min(minimum(root->left), minimum(root->right)));
}

bool isBST(BinaryTreeNode<int>* root) {
    if(root == NULL){
        return true;
    }

    int leftMax = maximum(root->left);
    int rightMin = minimum(root->right);
    bool output = root->data > leftMax && root->data < rightMin && isBST(root->left) && isBST(root->right);
    
    return output;
}

//using class method

class isBSTReturn{
    public:
    bool isBST;
    int minimum;
    int maximum;
};

isBSTReturn isBST2(BinaryTreeNode<int>* root){
    if(root == NULL){
        isBSTReturn output;
        output.isBST = true;
        output.minimum = INT_MAX;
        output.maximum = INT_MIN;
        return output;
    }

    isBSTReturn leftOutput = isBST2(root->left);
    isBSTReturn rightOutput = isBST2(root->right);

    int minimum = min(root->data, min(leftOutput.minimum, rightOutput.minimum));
    int maximum = max(root->data, min(leftOutput.maximum, rightOutput.maximum));
    bool isBSTFinal = (root->data > leftOutput.maximum) && (root->data <= rightOutput.minimum) && leftOutput.isBST && rightOutput.isBST;

    isBSTReturn output;
    output.minimum = minimum;
    output.maximum = maximum;
    output.isBST = isBSTFinal;
    
    return output;
}