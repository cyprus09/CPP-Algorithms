template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

template <typename T>
TreeNode<T>* takeInputLevelWise() {
    T rootData;
    cin >> rootData;
    TreeNode<T>* root = new TreeNode<T>(rootData);

    queue<TreeNode<T>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<T>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<T>* child = new TreeNode<T>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}