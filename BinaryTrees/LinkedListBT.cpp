/*Given a binary tree, write code to create a separate linked list for each level. 
You need to return the array which contains head of each level linked list.*/
#include <iostream>
#include <queue>
#include <vector>
#include "binarytree.h"
using namespace std;

template <typename T>
class Node {
   public:
    T data;
    Node<T> *next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    
	vector<Node<int>*> headNodes;

	if(root == NULL){
		return headNodes;
	}
	
	queue <BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	
	while(!pendingNodes.empty()){
		int n = pendingNodes.size();
		
		Node<int> *head = NULL;
        Node<int> *tail = NULL;

		while(n != 0){
			BinaryTreeNode<int>* curr = pendingNodes.front();
			pendingNodes.pop();
			Node<int>* newNode = new Node<int> (curr->data);

			if(head == NULL){
				head = newNode;
				tail = newNode;
			}
			else{
				tail->next = newNode;
				tail = newNode;
			}
			if(curr->left != NULL){
				pendingNodes.push(curr->left);
			}
			if(curr->right != NULL){
				pendingNodes.push(curr->right);
			}
			n--;
		}
		headNodes.push_back(head);
	}

	return headNodes;
}

void print(Node<int> *head) {
    Node<int> *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    BinaryTreeNode<int> *root = takeInput();
    vector<Node<int> *> ans = constructLinkedListForEachLevel(root);

    for (int i = 0; i < ans.size(); i++) {
        print(ans[i]);
    }
}