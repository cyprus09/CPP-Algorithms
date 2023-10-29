#include <iostream>
#include <climits>

using namespace std;

void heapify(int arr[], int n, int i){
    
    int parentIndex = i;
    int leftChildIndex = 2 * parentIndex + 1;
    int rightChildIndex = 2 * parentIndex + 2;

    while(leftChildIndex < n){
        int minIndex = parentIndex;

        if(arr[minIndex] > arr[leftChildIndex]){
            minIndex = leftChildIndex;
        }
        if(arr[minIndex] > arr[rightChildIndex] && rightChildIndex < n){
            minIndex = rightChildIndex;
        }
        if(minIndex == parentIndex){
            return;
        }

        int temp = arr[parentIndex];
        arr[parentIndex] = arr[minIndex];
        arr[minIndex] = temp;

        parentIndex = minIndex;
        leftChildIndex = 2 * parentIndex + 1;
        rightChildIndex = 2 * parentIndex + 2;
    }

}

void heapSort(int arr[], int n) {
    for (int i = (n / 2) - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;

        heapify(arr, i, 0); 
    }
}

int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    } 

    heapSort(input, size);

    for (int i = 0; i < size; i++) {
        cout << input[i] << " ";
    } 

    delete[] input;
}