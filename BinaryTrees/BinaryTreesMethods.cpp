#include <iostream>
#include <queue>
#include <climits>
#include "binarytree.h"
using namespace std;

int numNodes(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }

    return 1 + numNodes(root->left) + numNodes(root->right);
}

//recursive method to return bool for node presence
bool isNodePresent(BinaryTreeNode<int> *root, int x) {
 if (root == NULL) {
        return false;
    }
    if (root->data == x) {
        return true;
    }

    bool isLeftPresent = isNodePresent(root->left, x);
    bool isRightPresent = isNodePresent(root->right, x);

    return isLeftPresent || isRightPresent;
}

//another method using queue to check for node presence
bool isNodePresent(BinaryTreeNode<int> *root, int x) {

    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    while(!q.empty()){
        BinaryTreeNode<int>* front = q.front();
        q.pop();
        if(front->data == x){
            return true;
        }
        if(front->left != NULL){
            q.push(front->left);
        }
        if(front->right != NULL){
            q.push(front->right);
        }
    }

    return false;
}

int height(BinaryTreeNode<int>* root) {
    if(root == NULL){
		return 0;
	}

	int leftHeight = height(root->left);
	int rightHeight = height(root->right);
	
	return 1 + max(leftHeight, rightHeight);
}

void mirrorBinaryTree(BinaryTreeNode<int>* root) {
   
   if(root == NULL){
	   return;
   }

   mirrorBinaryTree(root->left);
   mirrorBinaryTree(root->right);

	BinaryTreeNode<int>* temp = root->left;
	root->left = root->right;
	root->right = temp;
}

int getSum(BinaryTreeNode<int>* root) {
    if(root == NULL){
		return 0;
	}
	return root->data + getSum(root->left) + getSum(root->right);
}

int diameter(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }

    int option1 = height(root->left) + height(root->right); //height() function described above
    int option2 = diameter(root->left);
    int option3 = diamter(root->right);

    return max(option1, max(option2, option3));
}

//better approach for diameter of binary tree
pair<int, int> heightDiameter(BinaryTreeNode<int>* root){
    if(root == NULL){
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<int, int> leftAns = heightDiameter(root->left);
    pair<int, int> rightAns = heightDiameter(root->right);

    int leftDiameter = leftAns.second;
    int leftHeight = leftAns.first;
    int rightDiameter = rightAns.second;
    int rightHeight = rightAns.first;

    int height = 1 + max(lh, rh);
    int diameter = max(leftHeight + rightHeight, max(leftDiameter, rightDiameter));
    pair<int, int> p;
    p.first = height;
    p.second = diameter;

    return p;
}

pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
	pair <int, int> ans;

	if(root == NULL){
		ans.first = INT_MAX;
		ans.second = INT_MIN;
		return ans;
	}

	ans.first = root->data;
	ans.second = root->data;

	pair<int, int> leftMinMax = getMinAndMax(root->left);
	pair<int, int> rightMinMax = getMinAndMax(root->right);

	ans.first = min(ans.first, min(leftMinMax.first, rightMinMax.first));
	ans.second = max(ans.second, max(leftMinMax.second, rightMinMax.second));

	return ans;
}

bool isBalanced(BinaryTreeNode<int> *root) {

	if(root == NULL){
		return true;
	}
	int heightLeft = height(root->left);
	int heightRight = height(root->right);

	if(abs(heightLeft - heightRight) < 1 && isBalanced(root->left) && isBalanced(root->right)){
		return true;
	}

	return false;
}

void printNodesWithoutSibling(BinaryTreeNode<int> *root) {
    if(root == NULL){
        return;
    }
    if(root->left == NULL || root->right == NULL){
        if(root->left == NULL && root->right != NULL){
            cout << root->right->data << " "; 
        }
        if(root->left != NULL && root->right == NULL){
            cout << root->left->data << " ";
        }
    }

    printNodesWithoutSibling(root->left);
    printNodesWithoutSibling(root->right);
}

//inserting a duplicate node after each node to its left
void insertDuplicateNode(BinaryTreeNode<int> *root) {
    if (root == NULL) {
        return;
    }

    BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(root->data);
    BinaryTreeNode<int> *temp = root->left;
    root->left = newNode;
    newNode->left = temp;
    
    insertDuplicateNode(temp);
    insertDuplicateNode(root->right);
}

//lowest common ancestor of binaryTree
int getLCA(BinaryTreeNode <int>* root , int a, int b) {
    if(root == NULL){
		return -1;
	}
	if(root->data == a || root->data == b){
		return root->data;
	}

	int ansLeft = getLCA(root->left, a, b);
	int ansRight = getLCA(root->right, a, b);

	if(ansLeft != -1 && ansRight == -1){
		return ansLeft;
	}else if(ansRight != -1 && ansLeft == -1){
		return ansRight;
	}else if(ansLeft != -1 && ansRight != -1){
		return root->data;
	}else{
		return -1;
	}
}