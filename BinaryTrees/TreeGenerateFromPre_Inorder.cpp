#include "binarytree.h"
#include <queue>
#include <iostream>
#include <climits>

using namespace std;

BinaryTreeNode<int> *takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void printLevelATNewLine(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        BinaryTreeNode<int> *first = q.front();
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

BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    
	int rootData = preorder[0];
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

	if (preLength == 1){
		return root;
	}else if (preLength == 0){
		return NULL;
	}

	int rootIndex = 0;
	for(int i = 0; inorder[i] != '\0'; i++){
		if(inorder[i] == rootData){
			rootIndex = i;
			break;
		}
	}

	int leftLength = rootIndex;
	int rightLength = inLength - rootIndex - 1;

	BinaryTreeNode<int> *left = buildTree(preorder + 1, leftLength, inorder, leftLength);
	BinaryTreeNode<int> *right = buildTree(preorder + leftLength + 1, rightLength, inorder + leftLength + 1, rightLength);

	root->left = left;
	root->right = right;

	return root;
}

//Another Approach using Maths and Helper Function
BinaryTreeNode<int>* buildTreeHelper(int *preorder, int *inorder, int inStart, int inEnd, int preStart, int preEnd){
	if(inStart > inEnd){
		return NULL;
	}
	
	int rootData = preorder[preStart];
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

	int rootIndex = -1;
	while(inorder[rootIndex] != rootData){
		rootIndex++;
	}

	int leftInStart = inStart;
	int leftInEnd = rootIndex - 1;
	int leftPreStart = preStart + 1;
	int leftPreEnd = leftPreStart + (leftInEnd - leftInStart);
	int rightInStart = rootIndex + 1;
	int rightInEnd = inEnd;
	int rightPreStart = leftPreEnd + 1;
	int rightPreEnd = preEnd;

	root->left = buildTreeHelper(preorder, inorder, leftInStart, leftInEnd, leftPreStart, leftPreEnd);
	root -> right = buildTreeHelper(preorder, inorder, rightInStart, rightInEnd, rightPreStart, rightPreEnd);

	return root;
}

BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    return buildTreeHelper(preorder, inorder, 0, inLength - 1, 0, preLength - 1);
}

BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    return buildTreeHelper(preorder, inorder, 0, inLength - 1, 0, preLength - 1);
}

int main() {
    int size;
    cin >> size;
    int *pre = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++) cin >> pre[i];
    for (int i = 0; i < size; i++) cin >> in[i];
    BinaryTreeNode<int> *root = buildTree(pre, size, in, size);
    printLevelATNewLine(root);
}