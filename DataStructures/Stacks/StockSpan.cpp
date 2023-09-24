#include <iostream>
#include <stack>
using namespace std;

void calculateSpan(int prices[], int n, int spans[]) {

    stack<int> stack;

    spans[0] = 1;
    stack.push(0);

    for (int i = 1; i < n; i++) {
        while (!stack.empty() && prices[stack.top()] < prices[i]) {
            stack.pop();
        }

        if (stack.empty()) {
            spans[i] = i + 1;
        } else {
            spans[i] = i - stack.top();
        }

        stack.push(i);
    }
}

int main() {
    int n;
    cin >> n;

    int* prices = new int[n];
    for (int i = 0; i < n; i++)
        cin >> prices[i];

    int* spans = new int[n];
    calculateSpan(prices, n, spans);

    for (int i = 0; i < n; i++)
        cout << spans[i] << " ";

    delete[] prices;
    delete[] spans;

    return 0;
}