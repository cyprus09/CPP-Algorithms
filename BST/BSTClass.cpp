#include <iostream>
#include <queue>
#include "BinarySearchTree.h"

using namespace std;

class BST {
    public:
    BinaryTreeNode<int>* root;
    public:
    BST() { 
        root = NULL;
    }

    ~BST(){
        delete root;
    }

    private:
    BinaryTreeNode<int>* findMinNode(BinaryTreeNode<int>* node){
        if(node->right == NULL){
            return node;
        }
        return findMinNode(node->left);
    }

    BinaryTreeNode<int>* deleteHelper(int data, BinaryTreeNode<int> *node){
        if(node == NULL){
            return NULL;
        }
        if(data > node->data){
            node->right = deleteHelper(data, node->right);
        }
        if(data < node->data){
            node->left = deleteHelper(data, node->left);
        }
        else{
            if(node->left == NULL && node->right == NULL){
                delete node;
                return NULL;
            }else if(node->right == NULL){
                BinaryTreeNode<int> *temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            }else if(node->left == NULL){
                BinaryTreeNode<int> *temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            }else{
                BinaryTreeNode<int> *minNode = findMinNode(node->right);
                node->data = minNode->data;
                node->right = deleteHelper(minNode->data, node->right);
                return node;
            }
        }
        return node;
    }
    void printHelper(BinaryTreeNode<int>* node){
        if(node == NULL){
            return;
        }

        cout << node->data << ":";
        
        if(node->left != NULL){
            cout << "L:" << node->left->data << ",";
        }
        if(node->right != NULL){
            cout << "R:" << node->right->data;
        }
        cout << endl;

        printHelper(node->left);
        printHelper(node->right);
    }

    BinaryTreeNode<int>* insertHelper(int data, BinaryTreeNode<int>* node){
        if (node == NULL) {
            BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }
        if(node->data >= data){
            node->left = insertHelper(data, node->left);
        }
        if(node->data < data){
            node->right = insertHelper(data, node->right);
        }

        return node;
    }

    bool searchHelper(BinaryTreeNode<int>* node, int data){
        if(node == NULL){
            return false;
        }

        if(node->data == data){
            return true;
        }else if(data > node->data){
            return searchHelper(node->right, data);
        }else{
            return searchHelper(node->left, data);
        }
    }
	/*----------------- Public Functions of BST -----------------*/
    public:
    void remove(int data) { 
       this->root = deleteHelper(data, this->root);
    }

    //printing the BST in the form as asked for
    void print() { 
        printHelper(root);
    }

    //inserting new nodes into the BST
    void insert(int data) { 
        this->root = insertHelper(data, this->root);
    }

    //searching whether an element is present in the BST or not
    bool search(int data) {
		return searchHelper(this->root, data);
    }
};