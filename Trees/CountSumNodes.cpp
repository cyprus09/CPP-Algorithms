#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T>
class TreeNode {
   public:
   T data;
   vector<TreeNode<T>*> children;  
   treeNode(T data){
    this -> data = data;
   }

   ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
   }
};

TreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout << "Enter root data: " << endl;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter number of children for " << front->data << endl;
        int numChild;
        cin >> numChild;
        for(int i = 0; i< numChild; i++){
            int childData;
            cout << "Enter " << i << "th child of " << front->data << endl;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

int numNodes(TreeNode<int>* root){
    int ans = 1;
    for(int i = 0; i < root->children.size(); i++){
        ans += numNodes(root->children[i]);
    }
    return ans;
}

int sumOfNodes(TreeNode<int>* root) {
    int sum = root -> data;
    for(int i = 0; i < root->children.size(); i++){
        sum += sumOfNodes(root->children[i]);
    }
    return sum;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    cout << sumOfNodes(root);
}
