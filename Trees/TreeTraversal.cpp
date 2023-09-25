#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class TreeNode {
   public:
   T data;
   vector<TreeNode<T>*> children;  // writing <T> is optional it just assumes the parent datatype
   treeNode(T data){
    this -> data = data;
   }
};

TreeNode<int>* takeInput(){
    int rootData;
    cout << "Enter data: " << endl;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    int n;
    cout << "Enter num of children of" << rootData << endl;
    cin >> n;
    for(int i = 0; i < n; i++){
        TreeNode<int> *child = takeInput();
        root -> children.push_back(child);
    }

    return root;
}

void printTree(TreeNode<int>* root){
    if(root == NULL){  //edge case not base case
        return;
    }
    cout << root -> data << endl;
    for(int i = 0; i < root -> children.size(); i++){
        cout << root ->children[i]->data << ',';
    }
    cout << endl;
    for(int i = 0; i < root -> children.size(); i++){
        printTree(root->children[i]); //recursion only acts as base case incase of trees for most cases
    }
}

int main(){
    TreeNode<int>* root = takeInput();
    printTree(root);
}
