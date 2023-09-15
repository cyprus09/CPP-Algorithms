#include <iostream>
#include <climits>
using namespace std;

class StackArray {
    int *data;
    int nextIndex;
    int capacity;

    public:
    StackArray(){
        data = new int[4];
        nextIndex = 0;
        capacity = 4;
    }

    int size(){
        return nextIndex;
    }

    bool isEmpty(){
        return nextIndex == 0;
    }

    void push(int element){
        if(nextIndex == capacity){
            int *newData = new int[2 * capacity];
            for(int i = 0; i < capacity; i++){
                newData[i] = data[i];
            }
            capacity *= 2;
            data = newData;
            delete[] data;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    int pop(){
        if(isEmpty()){
            cout << "Stack Empty!" << endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }

    int top(){
        if(isEmpty()){
            cout << "Stack Empty!" << endl;
            return INT_MIN;
        }
        return data[nextIndex - 1];
    }
};

int main(){
    StackArray s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;

    cout << s.size() << endl;
    cout << s.isEmpty() << endl;
}