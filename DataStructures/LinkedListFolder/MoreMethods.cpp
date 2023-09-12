#include <iostream>
using namespace std;

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

Node *skipMdeleteN(Node *head, int M, int N) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    if(M == 0){
        return NULL;
    }
    if(N == 0){
        return head;
    }

    Node *t1 = head, *t2 = NULL;

    while (t1 != NULL) {
        for (int count_M = 1; count_M < M && t1 != NULL; count_M++) {
            t1 = t1->next;
        }
        if (t1 == NULL) {
            break;
        }

        t2 = t1->next;
        for (int count_N = 1; count_N <= N && t2 != NULL; count_N++) {
            Node *temp = t2;
            t2 = t2->next;
            free(temp);
        }

        t1->next = t2;
        t1 = t2;
    }

    return head;
}

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

Node *swapNodes(Node *head, int i, int j)
{
	if(head == NULL || head -> next == NULL){
		return head;
	}
	if(i == j){
		return head;
	}

	Node *currentNode = head, *prevNode = NULL;
	Node *firstNode = NULL, *firstNodePrev = NULL, *secondNode = NULL, *secondNodePrev = NULL;
	int count = 0;

	while(currentNode != NULL){
		if(count == i){
			firstNodePrev = prevNode;
			firstNode = currentNode;
		}
		if(count == j){
			secondNodePrev = prevNode;
			secondNode = currentNode;
		}
		prevNode = currentNode;
		currentNode = currentNode -> next;
		count++;
	}

	if(firstNodePrev != NULL){
		firstNodePrev -> next = secondNode;
	}else{
		head = secondNode;
	}

	if(secondNodePrev != NULL){
		secondNodePrev -> next = firstNode;
	}else{
		head = firstNode;
	}

	Node *temp = secondNode -> next;
	secondNode -> next = firstNode -> next;
	firstNode -> next = temp;

	return head; 
}

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

	//Call for Skipping M nodes and Deleting N nodes

	// while (t--)
	// {
	// 	Node *head = takeinput();
	// 	int m, n;
	// 	cin >> m >> n;
	// 	head = skipMdeleteN(head, m, n);
	// 	print(head);
	// }
	return 0;
}