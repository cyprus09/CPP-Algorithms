#include <queue>
#include <vector>
#include <iostream>

using namespace std;  

//k smallest numbers from given array
vector<int> kSmallest(int arr[], int n, int k) {
    priority_queue<int> pq;
    vector <int> ans; 

    for(int i = 0; i < k; i++){
        pq.push(arr[i]);
    }

    for(int i = k; i < n; i++){
        if(arr[i] < pq.top()){
            pq.push(arr[i]);
            pq.pop();
        }
        if(arr[i] > pq.top()){
            continue;
        }
    }

    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }

    return ans;
}

//k largest numbers from given array T: O(nlogk) S: O(k)
/*  Note: for min-heap priority queue, can declare as "priority_queue<int, vector<int>, greater<int> > ans""*/
vector<int> kLargest(int input[], int n, int k){
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> ans;

    for(int i = 0; i < k; i++){
        pq.push(input[i]);
    }

    for(int i = k; i < n; i++){
        if(input[i] > pq.top()){
            pq.push(input[i]);
            pq.pop();
        }
        continue;
    }

    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }

    return ans;
}

//check for max-heap or not
//first approach using priority queue T: O(nlogn)
bool isMaxHeap(int arr[], int n) {
    priority_queue<int> pq;

    for(int i = 0; i < n; i++){
        pq.push(arr[i]);
    }
    for(int i = 0; i < n; i++){
        if(arr[i] != pq.top()){
            return false;
        }
        pq.pop();
    }
    return true;
}
//more optimal approach for bigger input values T: O(n)
bool isMaxHeap(int arr[], int n) {
    for(int i = 0; i < n ; i++){
        int leftChildIndex = 2 * i + 1;
        int rightChildIndex = 2 * i + 2;

        if(leftChildIndex < n && arr[i] < arr[leftChildIndex]){
            return false;
        }
        if(rightChildIndex < n && arr[i] < arr[rightChildIndex]){
            return false;
        }
    }
    return true;
}

//Kth largest in array
int kthLargest(vector<int>& arr, int k) {
    int n = arr.size();
    priority_queue<int> pq; 

    if (k > n) {
        return -1;
    }

    for (int i = 0; i < n; i++) {
        pq.push(arr[i]);
    }

    for (int i = 0; i < k - 1; i++) {
        pq.pop();
    }

    return pq.top();
}




