#include <climits>
#include <iostream>
#include <queue>
#include <vector>
#include "TreesClass.h"
using namespace std;

//first approach without recursion
TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    if(root == NULL || root->children.size() == 0){
        return NULL;
    } 

    TreeNode<int> *largest = root;
    TreeNode<int> *secondLargest=root->children[0];

    if(largest->data < secondLargest->data){
        secondLargest = root;
        largest=root->children[0];
    }

    queue<TreeNode<int>*> q;
    q.push(root);

    while(!q.empty()){
        TreeNode<int> *curr = q.front();
        q.pop();
        for(int i = 0; i < curr->children.size(); i++){
            q.push(curr->children[i]);
            if(curr->children[i]->data > secondLargest->data){
                if(curr->children[i]->data > largest->data){
                    secondLargest = largest;
                    largest = curr->children[i];
                }
                else{
                    secondLargest = curr->children[i];
                }
            }
        }
    }
    return secondLargest;
}

//second approach using helper function and recursion


