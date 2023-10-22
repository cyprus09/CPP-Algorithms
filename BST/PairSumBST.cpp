#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <climits>
#include "BinarySearchTree.h"

using namespace std;

void preOrderTraversal(BinaryTreeNode<int>* root, vector<int> &sortedValues){
	if(root == NULL){
		return;
	}

	sortedValues.push_back(root->data);
	preOrderTraversal(root->left, sortedValues);
	preOrderTraversal(root->right, sortedValues);
}
void pairSum(BinaryTreeNode<int> *root, int sum) {
   vector<int> sortedValues;
   if(root == NULL){
	   return;
   }
   preOrderTraversal(root, sortedValues);
   sort(sortedValues.begin(), sortedValues.end());

   int left = 0;
   int right = sortedValues.size() - 1;

   while(left < right){
	   int currentSum = sortedValues[left] + sortedValues[right];
	   if(currentSum == sum){
			cout << sortedValues[left] << " " << sortedValues[right] << endl;
			left++;
		   	right--;
	   }else if(currentSum < sum){
		   left++;
	   }else if(currentSum > sum){
		   right--;
	   }
   }
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int sum;
    cin >> sum;
    pairSum(root, sum);
    delete root;
}