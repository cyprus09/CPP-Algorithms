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

Node* insertNodeRecursively(Node *head, int pos, Node* newNode){
    if(pos == 0){
        newNode->next = head;
        return newNode;
    }else if(head == NULL){
        return head;
    }else{
        head -> next = InsertNode(head -> next, pos - 1, newNode);
        return head;
    }
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

Node *deleteNodeRecursively(Node *head, int pos) {
	if(head == NULL){
		return head;
	}else if(pos == 0){
		Node* a = head -> next;
		delete head;
		return a;
	}else{
		head -> next = deleteNodeRec(head -> next, pos -1);
		return head;
	}
}

Node *removeDuplicates(Node *head)
{
    Node *temp = head;
	if(head == NULL){
		return NULL;
	}
	while(temp != NULL && temp -> next != NULL){
		if(temp -> data == temp -> next -> data){
			Node *toDelete = temp -> next;
			temp -> next = temp -> next -> next;
			delete toDelete;
		}else{
			temp = temp -> next;
		}
	}
	return head;
}

int length(Node *head){
    int count = 0;
	Node *temp = head;
    while(temp != NULL){
        count++;
        temp = temp -> next;
    }
    return count;
}

int lengthRecursive(Node *head){
	Node *temp = head;
	if(temp == NULL){
		return 0;
	}else{
		return 1 + length(head->next);
	}
}

Node *appendLastNToFirst(Node *head, int n){	
	if(n <= 0 || head == NULL || head -> next == NULL){
		return head;
	}
    int count = 0;
	Node *temp = head;
	while(temp -> next != NULL){
		temp = temp -> next;
		count++;
	}
	if(n >= count){
		return head;
	}
	temp = head;
	for(int i = 0; i < count - n; i++){
		temp = temp -> next;
	}
	Node *newHead = temp -> next;
	temp -> next = NULL;
	Node *lastNode = newHead;
	while(lastNode -> next != NULL){
		lastNode = lastNode -> next;
	}
	lastNode -> next = head;
	return newHead;
}

Node *removeDuplicates(Node *head)
{
    Node *temp = head;
	if(head == NULL){
		return NULL;
	}
	while(temp != NULL && temp -> next != NULL){
		if(temp -> data == temp -> next -> data){
			Node *toDelete = temp -> next;
			temp -> next = temp -> next -> next;
			delete toDelete;
		}else{
			temp = temp -> next;
		}
	}
	return head;
}

void printIthNode(Node *head, int i){
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

void print(Node* head){
    while (head != NULL) {
        cout << head -> data << ' ';
        head = head -> next;
    }

}

Node *midPoint(Node *head)
{
    if(head == NULL){
       return NULL;
   }

   Node *slow = head;
   Node *fast = head -> next;

   while(fast != NULL && fast -> next != NULL){
	   slow = slow -> next;
	   fast = fast -> next -> next;
   }
   
   return slow;
}

void printReverse(Node *head)
{
	Node *curr = head;
	Node *prev = NULL, *next = NULL;

	while(curr != NULL){
		next = curr -> next;
		curr -> next = prev;
		prev = curr;
		curr = next;
	}
	head = prev;

	Node *temp = head;
	while(temp != NULL){
		cout << temp -> data << ' ';
		temp = temp -> next;
	}
}

Node *reverseLinkedListRec(Node *head)
{
    if(head == NULL || head -> next == NULL){
		return head;
	}
	Node *rest = reverseLinkedListRec(head -> next);
	Node *tail = head -> next;
    tail -> next = head;
	head -> next = NULL;

	return rest;
}

Node *reverseLinkedListIteratively(Node *head) {
    if(head == NULL || head -> next == NULL){
		return head;
	}

	Node *prev = NULL;
	Node *curr = head;
	Node *next = NULL;

	while(curr != NULL){
		next = curr -> next;
		curr -> next = prev;
		prev = curr;
		curr = next;
	}

	return prev;
}

bool isPalindrome(Node *head)
{   
	if (head == NULL || head->next == NULL) {
        return true; 
    }

    Node *slow = head;
    Node *fast = head -> next;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *prev = NULL;
    Node *curr = slow->next;
    Node *temp;

    while (curr != NULL) {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    Node *left = head;
    Node *right = prev;

    while (right != NULL) {
        if (left->data != right->data) {
            return false;
        }
        left = left->next;
        right = right->next;
    }
	return true;
}

bool detectCycle(Node *head)
{
    if(head == NULL || head -> next == NULL){
        return false;
    }
    Node *slow = head;
	Node *fast = head -> next;
    while(fast != NULL && fast -> next != NULL){
       slow = slow -> next;
       fast = fast -> next -> next;

       if(slow == fast){
        return true;
    }
    }
    
    return false;
}

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2){
    
	if(head1 == NULL){
		return head2;
	}else if(head2 == NULL){
		return head1;
	}

	Node *firstHead = NULL;

    if(head1 -> data <= head2 -> data){
		firstHead = head1;
		head1 = head1 -> next;
	}else if(head1 -> data > head2 -> data){
		firstHead = head2;
		head2 = head2 -> next;
	}

	Node *firstTail = firstHead;

	while(head1 != NULL && head2 != NULL){
		Node *temp = NULL; 
		if(head1 -> data <= head2 -> data){
			temp = head1;
			head1 = head1->next;
        } else {
			temp = head2;
			head2 = head2->next;
		}

		firstTail -> next = temp;
		firstTail = temp;
	}

	if (head1 != NULL) {
    	firstTail -> next = head1;
  	} else if (head2 != NULL) {
    	firstTail -> next = head2;
  	}
	return firstHead;
}


int main() {

    Node *head = takeInput();

    //Node Insertion
    int i, data;
    cin >> i >> data;
    head = insertNode(head, i , data);
    
    //Node Deletion
    int pos;
	cin >> pos;
	head = deleteNode(head, pos);

    print(head);

    return 0;
}