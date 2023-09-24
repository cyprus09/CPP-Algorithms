#include <stack>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

int countBracketReversals(string input) {
	if (input.length() % 2 != 0) {
        return -1;
    }

    stack<char> stack;
    int count = 0;

    for (int i = 0; i < input.length(); i++) {
        char c = input[i];

        if (c == '{') {
            stack.push(c);
        } else {
            if (stack.empty()) {
                stack.push(c);
            } else if (stack.top() == '}') {
                stack.push(c);
            } else if (stack.top() == '{') {
                stack.pop();
            }
        }
    }

    while (!stack.empty()) {
        char c1 = stack.top();
        stack.pop();
        char c2 = stack.top();
        stack.pop();

        if (c1 == c2) {
            count = count + 1;
        } else {
            count = count + 2;
        }
    }

    return count;
}

int main() {
    string input;
    cin >> input;
    cout << countBracketReversals(input);
}