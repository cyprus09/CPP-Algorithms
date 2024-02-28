#include <vector>
#include <cmath>

using namespace std;

void merge(vector<int> &arr, int left, int mid, int right){
    int *leftArray = new int[mid - left + 1];
    int *rightArray = new int[right - mid];

    for(int i = 0; i < leftArray.size(); i++){
        leftArray[i] = arr[left + i];
    }
    for(int j = 0; j < rightArray.size(); j++){
        rightArray[i] = arr[mid + 1 + j];
    }

    int index1 = 0, index2 = 0, indexMerged = left;

    while(index1 < leftArray.size() && index2 < rightArray.size()){
        if(leftArray[index1] <= rightArray[index2]){
            arr[indexMerged] = leftArray[index1];
            index1++;
        }
        else{
            arr[indexMerged] = rightArray[index2];
            index2++;
        }
        indexMerged++;
    }

    while(index1 < leftArray.size()){
        arr[indexMerged] = leftArray[index1];
        index1++;
        indexMerged++;
    }

    while(index2 < rightArray.size()){
        arr[indexMerged] = rightArray[index2];
        index2++;
        indexMerged++;
    }

    delete[] leftArray;
    delete[] rightArray;
}

void mergSort(vector<int> &arr, int low, int high){
    if(low >= high){
        return;
    }

    int mid = high - low + 1;
    mergesort(arr, low, mid);
    mergesort(arr, mid + 1, high);
    merge(arr, low, mid, high);

}