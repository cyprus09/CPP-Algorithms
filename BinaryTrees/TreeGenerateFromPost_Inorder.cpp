#include <iostream>
#include <queue>
#include "binarytree.h"

using namespace std;

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

BinaryTreeNode<int>* buildTreeHelper(int *postorder, int *inorder, int inStart, int inEnd, int postStart, int postEnd){
	if(inStart > inEnd){
		return NULL;
	}
	int rootData = postorder[postEnd];
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	
	int rootIndex = inStart;
    while(inorder[rootIndex] != rootData){
        rootIndex++;
    }

	int leftInStart = inStart;
	int leftInEnd = rootIndex - 1;
	int leftPostStart = postStart;
	int leftPostEnd = (leftInEnd - leftInStart) + leftPostStart;
	int rightInStart = rootIndex + 1;
	int rightInEnd = inEnd;
	int rightPostStart = leftPostEnd + 1;
	int rightPostEnd = postEnd - 1;

	root->left = buildTreeHelper(postorder, inorder, leftInStart, leftInEnd, leftPostStart, leftPostEnd);
	root->right = buildTreeHelper(postorder, inorder, rightInStart, rightInEnd, rightPostStart, rightPostEnd);

	return root;
}

BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
    return buildTreeHelper(postorder, inorder, 0, inLength - 1, 0, postLength - 1);
}

int main() {
    int size;
    cin >> size;
    int *post = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++) cin >> post[i];
    for (int i = 0; i < size; i++) cin >> in[i];
    BinaryTreeNode<int> *root = buildTree(post, size, in, size);
    printLevelATNewLine(root);
}