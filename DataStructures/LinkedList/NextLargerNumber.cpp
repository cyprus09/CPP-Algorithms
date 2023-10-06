#include <iostream>
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

Node* helper(Node *head) {
    
    if(head -> next == NULL){
        head -> data++;
        return head;
    }
    head -> next = helper(head -> next);
     
    if(head -> next -> data > 9) {
        head -> next -> data = 0;
        head -> data += 1;
    }
    
    return head;
}

Node* NextLargeNumber(Node *head) {
    head = helper(head);

    if(head -> data > 9) {
        Node *newNode = new Node(1);
        head -> data = 0;
        newNode -> next = head;
        head = newNode;
    }
    return head;   
}

using namespace std;

Node* takeinput() {
    int data;
    cin >> data;
    Node* head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL)                  {
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main() {
    Node *head = takeinput();
    
    head = NextLargeNumber(head);
    print(head);
    return 0;
}
