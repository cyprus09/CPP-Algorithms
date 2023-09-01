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