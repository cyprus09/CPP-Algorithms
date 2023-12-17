#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;

int highestFrequency(int arr[], int n) {
    unordered_map<int, int> numbers;

    for(int i = 0; i < n; i++){
        int element = arr[i];
        if(numbers.count(arr[i]) > 0){
            numbers[arr[i]] += 1;
        }else{
            numbers[arr[i]] = 1;
        }
    }

    int maxCount = INT_MIN, maxValue = arr[0];

    for(int i = 0; i < n; i++){
        if(numbers[arr[i]] > maxCount){
            maxCount = numbers[arr[i]];
            maxValue = arr[i];
        }
     }

    return maxValue;
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << highestFrequency(arr, n);

    delete[] arr;
}