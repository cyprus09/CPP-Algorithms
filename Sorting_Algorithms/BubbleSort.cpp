#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int j = 0; j < n - 1; j++) {
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
}

int main() {
    string input;
    getline(cin, input);  

    istringstream iss(input);  // Create a stringstream to parse the string.
    vector<int> arr;
    int num;

    while (iss >> num) {
        arr.push_back(num);
    }

    bubbleSort(arr);

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
