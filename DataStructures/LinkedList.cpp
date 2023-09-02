#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

Node * takeInput(){
    int data;
    cin >> data;

    Node *head = NULL;
    Node *tail = NULL;
    
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }else{
            tail -> next = newNode;
            tail = tail -> next;
        }
        cin >> data;
    }

    return head;
}

Node* insertNode(Node *head, int i, int data){
    Node *newNode = new Node(data);
    int count = 0;
    Node *temp = head;
    if(i == 0){
        newNode -> next = head;
        head = newNode;
        return head;
    }
    while(temp != NULL && count < i - 1){
        temp = temp -> next;
        count++;
    }
    if(temp != NULL){
        Node *a = temp -> next;
        temp -> next = newNode;
        newNode -> next = a;
    }
    return head;
}

Node *deleteNode(Node *head, int pos){
    if (pos == 0){
		if (head == NULL){
            return NULL;
        }
        Node *newHead = head->next;
        delete head;
        return newHead;
    }
    Node *temp = head;
    int count = 0;
    while (temp != NULL && count < pos - 1){
        temp = temp->next;
        count++;
    }
    if (temp == NULL || temp->next == NULL){
		return head;
    }
    Node *toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
    return head;
}

int length(Node *head)
{
    int count = 0;
	Node *temp = head;
    while(temp != NULL){
        count++;
        temp = temp -> next;
    }
    return count;
}

void printIthNode(Node *head, int i)
{
    Node *temp = head;
	int count = 0;
	while(temp != NULL){
		if(count == i){
			cout << temp -> data << endl;
			return;
		}else{
			temp = temp -> next;
		}
		count++;
	}
	return;
}

void print(Node* head) {
    while (head != NULL) {
        cout << head -> data << ' ';
        head = head -> next;
    }

}

int main() {

    Node *head = takeInput();
    print(head);
    int i, data;
    cin >> i >> data;
    head = insertNode(head, i , data);
    print(head);


    // //Statically
    // Node n1(1);   // Head node
    // Node* head = &n1;
    // Node n2(2);
    // n1.next = &n2;

    //Dynamically
    // Node *n3 = new Node(10);
    // Node *head = n3;
    // Node *n4 = new Node(20);
    // n3 -> next = n4;

    return 0;
}