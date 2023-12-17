#include <unordered_map>
#include <iostream>

using namespace std;

int pairSum(int *arr, int n) {
    unordered_map<int,int> freq;
    
    for(int i = 0;i<n;i++){
        freq[arr[i]]++;
    }

    int count = 0;
    for(int i = 0;i<n;i++){
        if(freq.find(arr[i])!=freq.end() && freq.find(-arr[i])!=freq.end()){
        if(freq[arr[i]] == freq[-arr[i]]){
            count = count + 2*freq[arr[i]];
          
            freq.erase(arr[i]);
          
        }
        }
        if(freq.find(arr[i])!=freq.end() && freq.find(-arr[i])!=freq.end()){
          if(freq[arr[i]]>freq[-arr[i]]){
              count = count + freq[arr[i]];
          
              freq.erase(arr[i]);
          }
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << pairSum(arr, n);

    delete[] arr;
}