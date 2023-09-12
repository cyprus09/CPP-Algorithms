#include <iostream>
using namespace std;

Node *evenAfterOdd(Node *head){
	
	if(head == NULL || head -> next == NULL){
		return head;
	}

	Node *oddHead = NULL;
	Node *evenHead = NULL;
	Node *oddTail = NULL; 
    Node *evenTail = NULL;

	while (head != NULL) {
        if (head->data % 2 == 0) {
            if (evenHead == NULL) {
                evenHead = head;
                evenTail = head;
            } else {
                evenTail->next = head;
                evenTail = evenTail->next;
            }
        } else {
            if (oddHead == NULL) {
                oddHead = head;
                oddTail = head;
            } else {
                oddTail->next = head;
                oddTail = oddTail->next;
            }
        }
        head = head->next;
    }

	if (evenTail != NULL) {
        evenTail->next = NULL;
    }
    if (oddTail != NULL) {
        oddTail->next = NULL;
    }

	if (oddHead != NULL) {
        oddTail->next = evenHead;
        return oddHead;
    } else {
        return evenHead;
    }

	return oddHead;	
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
		head = evenAfterOdd(head);
		print(head);
	}
	return 0;
}