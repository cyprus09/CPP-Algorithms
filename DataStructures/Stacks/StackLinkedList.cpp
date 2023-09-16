#include <iostream>
using namespace std;
template <Typename T>

class Node {
    public:
    int data;
    Node *next;

    Node (int data){
        this -> data = data;
        next = NULL;
    }
};

class Stack {
	// Define the data members
   public:
    Stack() {
        // Implement the Constructor
    }

	/*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function
    }

    bool isEmpty() {
        // Implement the isEmpty() function
    }

    void push(int element) {
        // Implement the push() function
    }

    int pop() {
        // Implement the pop() function
    }

    int top() {
        // Implement the top() function
    }
};

int main() {
    Stack st;

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
                cout << ((st.isEmpty()) ? "true\n" : "false\n");
                break;
        }
    }
}