#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T>*> children;
    
    TreeNode(T data){
        this -> data = data;
    }
    
    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
   }
};

void takeInput(){
    int rootData;
    cout << "Enter root data: " << endl;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<T> (rootData);

    queue TreeNode<int>* pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter number of children for " << front->data << endl;
        int numChild;
        cin >> numChild;
        for(int i = 0; i < numChild; i++){
            int childData;
            cout << "Enter " << i << "th child of " << front->data << endl;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int> (childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

void printNodeAtKLevel(TreeNode<int>* root, int k){
    if(root == NULL){
        return;
    }
    if(k == 0){
        cout << root -> data << endl;
        return;
    }
    for(int i = 0; i < root->children.size(); i++){
        printNodeAtKLevel(root->children[i]; k - 1);
    }
}

int main(){
    
}