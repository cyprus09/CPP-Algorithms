#include <iostream>
using namespace std;

Node *slowFastApproach(Node *head){
	
	Node *slow = head;
	Node *fast = head -> next;

	while(fast != NULL && fast -> next != NULL){
		slow = slow -> next;
		fast = fast -> next -> next;
	}
	return slow;
}

Node* merge(Node* left, Node* right) {
    Node* head_new = new Node(-1);
    Node* curr = head_new;

    while (left != NULL && right != NULL) {
        if (left->data <= right->data) {
            curr->next = left;
            left = left->next;
        } else {
            curr->next = right;
            right = right->next;
        }
        curr = curr->next;
    }

    // Append the remaining nodes from either list
    while (left != NULL) {
        curr->next = left;
        left = left->next;
        curr = curr->next;
    }
    while (right != NULL) {
        curr->next = right;
        right = right->next;
        curr = curr->next;
    }

    return head_new->next;
}


Node *mergeSort(Node *head){
	
	if (head -> next == NULL){
        return head;
    }
    Node *mid = slowFastApproach(head);
    Node *start_of_right = mid->next;

    mid->next = NULL;

    Node *left = mergeSort(head);
    Node *right = mergeSort(start_of_right);

    Node *new_head = merge(left, right);

    return new_head;
}

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};


Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		head = mergeSort(head);
		print(head);
	}

	return 0;
}