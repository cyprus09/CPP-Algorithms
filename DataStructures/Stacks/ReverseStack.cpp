#include <iostream>
#include <stack>
using namespace std;

void reverseStack(stack<int> &input, stack<int> &extra) {
    stack<int> thirdStack;
    while(!input.empty()){
        extra.push(input.top());
        input.pop();
    }

    while(!extra.empty()){
        thirdStack.push(extra.top());
        extra.pop();
    }

    while(!thirdStack.empty()){
        input.push(thirdStack.top());
        thirdStack.pop();
    }
}

int main() {
    stack<int> input, extra;
    int size;
    cin >> size;

    for (int i = 0, val; i < size; i++) {
        cin >> val;
        input.push(val);
    }

    reverseStack(input, extra);

    while (!input.empty()) {
        cout << input.top() << " ";
        input.pop();
    }
}