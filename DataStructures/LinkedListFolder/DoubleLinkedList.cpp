#include <iostream>
using namespace std;

class Node{
public:
	int data;
	Node *next;
	Node* prev;
	Node(int data){
		this->data = data;
		this->next = NULL;
		this->prev = NULL;
	}
};

bool palindromeDLL(Node* head){
    if (head == NULL || head -> next == NULL)
       return true;

	Node *temp = head;
    Node *endPoint = head;
    while (endPoint->next != NULL)
        endPoint = endPoint->next;
 
    while (temp != endPoint){
        if (temp->data != endPoint->data)
            return false;
         
        if(temp->next == endPoint)
          break;
        temp = temp->next;
        endPoint = endPoint->prev;
    }
 
    return true;
}

Node *takeinput(){
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1){
		Node *newNode = new Node(data);
		if (head == NULL){
			head = newNode;
			tail = newNode;
		}
		else{
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}



int main(){
    
	int t;
	cin >> t;
	while (t--){
		Node *head = takeinput();
		bool ans = palindromeDLL(head);
		
		if (ans) cout << "true";
		else cout << "false";

		cout << endl;
	}
	return 0;
}