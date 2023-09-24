#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool checkRedundantBrackets(string expression) {
	stack<char> st;

    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == ')') {
            bool foundOperator = false;

            while (!st.empty() && st.top() != '(') {
                if (st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/') {
                    foundOperator = true;
                }
                st.pop();
            }

            st.pop(); 

            if (!foundOperator) {
                return true;
            }
        } else {
            st.push(expression[i]);
        }
    }
    return false;
}

int main() {
    string input;
    cin >> input;
    cout << ((checkRedundantBrackets(input)) ? "true" : "false");
}