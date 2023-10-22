#include <iostream>
#include <queue>
#include "BinarySearchTree.h"
#include <climits>

using namespace std;

//first approach using height function and checking if BST
int findHeight(BinaryTreeNode<int>* root){
    if (root == NULL)
        return 0;

    if (root->left == nullptr && root->right == NULL)
        return 1;

    return 1 + max(findHeight(root->left), findHeight(root->right));
}

bool isBST(BinaryTreeNode<int>* root, int min, int max){
    if (root == NULL)
        return true;

    if (root->data < min || root->data > max)
        return false;
    else
        return isBST(root->left, min, root->data - 1) && isBST(root->right, root->data + 1, max);
}

int largestBSTSubtree(BinaryTreeNode<int> *root) {
        if (root == NULL)
        return 0;
        
    if (isBST(root, INT_MIN, INT_MAX))
        return findHeight(root);
    else
    {
        return max(largestBSTSubtree(root->left), largestBSTSubtree(root->right));
    }
}

//second approach defining a class
class BSTReturn{
	public:
	int min;
	int max;
	int height;
	bool isBST;
};

BSTReturn largestBSTSubtreeHelper(BinaryTreeNode<int>* root){
	if(root == NULL){
		BSTReturn ans;
		ans.min = INT_MAX;
		ans.max = INT_MIN;
		ans.height = 0;
		ans.isBST = true;
		return ans;
	}
	
	BSTReturn left = largestBSTSubtreeHelper(root->left);
	BSTReturn right = largestBSTSubtreeHelper(root->right);

	if(!(right.isBST && right.min > root->data)){
		right.isBST = false;
	}
	if(!(left.isBST && left.max < root->data)){
		left.isBST = false;
	}

	BSTReturn ans;
	if(!left.isBST || !right.isBST || left.max > root->data || right.min < root->data){
		if(left.height > right.height){
			left.isBST = false;
			return left;
		}else{
			right.isBST = false;
			return right;
		}
	}
	ans.isBST = true;
	ans.min = min(root->data, min(left.min, right.min));
	ans.max = max(root->data, max(left.max, right.max));
	ans.height = 1 + max(left.height, right.height);

	return ans;
}

int largestBSTSubtree(BinaryTreeNode<int> *root) {
    return largestBSTSubtreeHelper(root).height;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << largestBSTSubtree(root);
    delete root;
}