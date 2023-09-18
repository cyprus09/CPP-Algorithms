#include <iostream>
using namespace std;

template <typename T>
class Node {
   public:
    T data;
    Node<T> *next;

    Node(T data) {
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class Stack {
	
    Node<T> *head;
    int size;

   public:
    Stack() {
        head = NULL;
        size = 0;
    }

    int getSize() {
        return size;
    }

    bool empty() {
        return size == 0;
    }

    void push(int element) {
        Node<T> *newNode = new Node<T>(element);
        newNode -> next = head;
        head = newNode;
        size++;
    }

    T pop() {
        if(empty()){
            return -1;
        }
        Node<T> *temp = head;
        T deleteValue = temp -> data;
        head = head -> next;
        delete temp;
        size--;
        return deleteValue;
    }

    T top() {
        if(empty()){
            return -1;
        }
        return head -> data;
    }
};

int main() {
    Stack<int> st;

    int q;
    cin >> q;

    while (q--) {
        int choice, input;
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                st.push(input);
                break;
            case 2:
                cout << st.pop() << "\n";
                break;
            case 3:
                cout << st.top() << "\n";
                break;
            case 4:
                cout << st.getSize() << "\n";
                break;
            default:
                cout << ((st.empty()) ? "true\n" : "false\n");
                break;
        }
    }
}