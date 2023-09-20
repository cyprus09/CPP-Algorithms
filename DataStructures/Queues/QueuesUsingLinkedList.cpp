#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class Node{
    public:
    T data;
    Node<T> *next;

    Node(T data){
        this -> data = data;
        next = NULL;
    }
};

template <typename T>
class Queue {
	
	Node<T> *head;
	Node<T> *tail;
	int size;

   public:
    Queue() {
		head = NULL;
		tail = NULL;
		size = 0;
	}
	
	/*----------------- Public Functions of Stack -----------------*/

	int getSize() {
		return size;
	}

    bool isEmpty() {         //empty() for inbuilt function
		return size == 0;
	}

    void enqueue(T data) {  //push() for inbuilt function and return type void
		Node<T> *temp = new Node(data);
		if(head == NULL){
			head = temp;
			tail = temp;
		}
		tail -> next = temp;
		tail = temp;
		size++;
	}

    T dequeue() {       //pop() for inbuilt function and return type void
        if(isEmpty()){
			return -1;
		}
		Node<T> *temp = head;
		int ans = temp -> data;
		head = head -> next;
		delete temp;
		size--;
		return ans;
    }

    T front() {
		if(isEmpty()){
			return -1;
		}
        return head -> data;
    }
};

int main() {
    Queue<int> q;

    int t;
    cin >> t;

    while (t--) {
        int choice, input;
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                q.enqueue(input);
                break;
            case 2:
                cout << q.dequeue() << "\n";
                break;
            case 3:
                cout << q.front() << "\n";
                break;
            case 4:
                cout << q.getSize() << "\n";
                break;
            default:
                cout << ((q.isEmpty()) ? "true\n" : "false\n");
                break;
        }
    }
}