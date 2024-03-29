#include <iostream>
#include <queue>

using namespace std;

void findMedian(int *arr, int n){
    priority_queue<int> s; 
    priority_queue<int,vector<int>,greater<int> > g;
 
    int med = arr[0];
    s.push(arr[0]);
 
    cout << med << " ";
 
    for (int i=1; i < n; i++){
        int x = arr[i];
 
        if (s.size() > g.size()){
            if (x < med){
                g.push(s.top());
                s.pop();
                s.push(x);
            }
            else
                g.push(x);
 
            med = (s.top() + g.top())/2;
        }
 
        else if (s.size()==g.size()){
            if (x < med){
                s.push(x);
                med = (int)s.top();
            }
            else{
                g.push(x);
                med = (int)g.top();
            }
        }
 
        else{
            if (x > med){
                s.push(g.top());
                g.pop();
                g.push(x);
            }
            else
                s.push(x);

            med = (s.top() + g.top())/2;
        } 
        cout << med << " ";
    }
}

int main(){
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    findMedian(arr,n);

    delete[] arr;
}