#include <iostream>
#include <queue>
#include <vector>
#include "TreeClass.h"
using namespace std;

//checking if a node with value int 'x' is present in the tree or not
bool isPresent(TreeNode<int>* root, int x) {
    if(root == NULL){
        return false;
    }
    bool present = false;
    present = present || (root->data == x);

    for(int i = 0; i < root->children.size(); i++){
        present = present || isPresent(root->children[i], x);
    }
    return present;
}

//counting number of nodes with value greater than int 'x'
int getLargeNodeCount(TreeNode<int>* root, int x) {
    if(root == NULL){
        return 0;
    }

    int count = 0;
    if(root->data > x){
        count += 1;
    }
    for(int i  = 0; i < root->children.size(); i++){
        count += getLargeNodeCount(root->children[i], x);
    }

    return count;
}

//checking if two trees are identical 
bool areIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {
    
    if(root1 == NULL && root2 == NULL){
        return true;
    }
    if(root1 == NULL || root2 == NULL){
        return false;
    }
    
    bool identical = true;

    if(root1->data != root2->data){
        identical = false;
    }
    if(root1->children.size() != root2->children.size()){
        identical = false;
    }

    for(int i = 0; i < root1->children.size() && i < root2->children.size(); i++){
        if(!(areIdentical(root1->children[i], root2->children[i]))){
            identical = false;
        }
    }

    return identical;
}

TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int x) {
    if (root == NULL) {
        return NULL;
    }
    
    TreeNode<int>* nextLargerNode = NULL;
    
    if (root->data > x && (nextLargerNode == NULL || root->data < nextLargerNode->data)) {
        nextLargerNode = root;
    }
    
    for (int i = 0; i < root->children.size(); i++) {
        TreeNode<int>* curr = getNextLargerElement(root->children[i], x);
        
        if (curr != NULL) {
            if (nextLargerNode == NULL || curr->data < nextLargerNode->data) {
                nextLargerNode = curr;
            }
        }
    }
    
    return nextLargerNode;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    int x;
    cin >> x;

    //check if node with value x is present
    cout << (isPresent(root, x) ? "true" : "false");

    //count number of larger node values
    cout << getLargeNodeCount(root, x);

    //check if identical
    TreeNode<int>* root1 = takeInputLevelWise();
    TreeNode<int>* root2 = takeInputLevelWise();
    cout << (areIdentical(root1, root2) ? "true" : "false");

    //next largest
    TreeNode<int>* ans = getNextLargerElement(root, x);
    if (ans != NULL) {
        cout << ans->data;
    }
}