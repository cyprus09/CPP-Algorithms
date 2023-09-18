#include <iostream>
using namespace std;

template <typename T>
class QueueUsingArray{
    
    T *data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;

    public:
    QueueUsingArray(int s){
        data = new T[s];
        nextIndex = 0;
        firstIndex = -1;
        size = 0;
        capacity = s;
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        return size == 0; 
    }

    void enqeue(T element){
        if(size == capacity){
            T *newData = new T[2 * capacity];
            int j = 0
            for(int i = firstIndex; i < capacity; i++){
                newData[j] = data[i];
                j++;
            }
            for(int i = 0; i < firstIndex; i++){
                newData[j] = data[i];
                j++;
            }
            delete[] data;
            data = newData;
            firstIndex = 0;
            nextIndex = capacity;
            capacity *= 2;
        }
        data[nextIndex] = element;
        nextIndex = (nextIndex + 1) % capacity;
        if(firstIndex == -1){
            firstIndex = 0;
        }
        size++;
    }

    T front(){
        if(isEmpty()){
            cout << "Queue is empty!" << endl;
            return 0;
        }
        return data[firstIndex];
    }

    T dequeue() {
        if(isEmpty()){
            cout << "Queue is empty!" << endl;
            return 0;
        }
        T ans = data[firstIndex];
        firstIndex = (firstIndex + 1) % capacity;
        size--;
        if(size == 0){
            firstIndex = -1;
            nextIndex = 0;
        }
        return ans;
    }

};

int main(){
    QueueUsingArray<int> q(5);

    q.enqeue(10);
    q.enqeue(20);
    q.enqeue(30);
    q.enqeue(40);
    q.enqeue(50);
    q.enqeue(60);

    cout << q.front() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    cout << q.getSize() << endl;
    cout << q.isEmpty() << endl;

}