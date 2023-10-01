#include <vector>
#include <iostream>
#include <queue>
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

//take input level wise
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

void printLevelWise(TreeNode<int>* root) {
    if (root == NULL) {
        return;
    }
    
    queue<TreeNode<int>*> q;
    q.push(root);
    
    while(!q.empty()){

        TreeNode<int> *curr = q.front();
        q.pop();
        cout << curr->data << ':';

        int childCount = curr->children.size();

        if(childCount){
            cout << curr->children[0]->data;
            q.push(curr->children[0]);
        }
        for(int i=1; i<childCount; i++){
            cout << ',' <<  curr->children[i]->data; 
            q.push(curr->children[i]);
        }
        cout << endl;
    }
}

int main(){
    TreeNode<int>* root = takeInputLevelWise();
    printLevelWise(root);

    return 0;
}