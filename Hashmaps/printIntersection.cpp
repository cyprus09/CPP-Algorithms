#include <bits/stdc++.h>
using namespace std;

void printIntersection(int arr1[], int arr2[], int n, int m) {
    unordered_map<int, int> matchNum;

    for(int i = 0; i < n; i++){
        if(matchNum.count(arr1[i]) > 0){
            matchNum[arr1[i]] += 1;
        }else{
            matchNum[arr1[i]] = 1;
        }
    }

    sort(arr2, arr2 + m);

    for (int i = 0; i < m; i++){
        if(matchNum.count(arr2[i]) > 0){
            int val = matchNum[arr2[i]];
            if(val > 0){
                cout << arr2[i] << endl;
                matchNum[arr2[i]] -= 1;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    int* arr1 = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr1[i];
    }

    int m;
    cin >> m;

    int* arr2 = new int[m];

    for (int i = 0; i < m; ++i) {
        cin >> arr2[i];
    }

    printIntersection(arr1, arr2, n, m);

    delete[] arr1;
    delete[] arr2;
}