#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;


template <Typename V>
class MapNode{
    public:
        string key;
        V value;
        MapNode* next;

    MapNode(string key, V value){
        this->key = key;
        this->value = value;
        next = NULL;
    }

    ~MapNode(){
        delete next;
    }
};

template <Typename V>
class Map{
    MapNode<V>** buckets;
    int size;
    int numBuckets;

    public:
    Map(){
        count = 0;
        numBuckets = 5;
        buckets = new MapNode<V>*[numBuckets];
        for(int i = 0; i < numBuckets; i++){
            buckets[i] = NULL;
        }
    }

    ~Map() {
        for(int i = 0; i < numBuckets; i++){
            delete buckets[i];
        }
        delete [] buckets;
    }

    int size(){
        return count;
    }

    V getValue(string key){
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex];
        while(head != NULL){
            if(head->key == key){
                return head->value;
            }
            head = head->next;
        }
        return 0;
    }
    private:
    int getBucketIndex(string key){
        int hashCode = 0;
        int currentCoeff = 1;

        for(int i = key.length() - 1; i >= 0; i--){
            hashCode += key[i] * currentCoeff;
            hashCode = hashCode % numBuckets;
            currentCoeff *= 37;
            currentCoeff = currentCoeff % numBuckets;
        }

        return hashCode % numBuckets;
    }

    //rehashing function if n/b > 0.7
    void rehash(){
        MapNode<V>** temp = buckets;
        buckets = new MapNode<V>*[2*numBuckets];
        for(int i = 0; i < 2*numBuckets; i++){
            buckets[i] = NULL;
        }
        int oldBucketCount = numBuckets;
        numBuckets *= 2;
        count = 0;

        for(int i = 0; i < oldBucketCount; i++){
            MapNode<V>** head = temp[i];
            while(head != NULL){
                string key = head->key;
                V value = head->value;
                insert(key, value);
                head = head->next;
            }
        }

        for(int i = 0; i < oldBucketCount; i++){
            MapNode<V>* head = temp[i];
            delete head;
        }
        delete[] temp;
    }

    public:
    
    double getLoadFactor(){
        return (1.0*count)/numBuckets;
    }

    void insert(string key, V value){
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex];
        while(head != NULL){
            if(head->key == key){
                head->value = value;
                return;
            }
            head = head->next;
        }
        head = buckets[bucketIndex];
        MapNode<V>* node = new MapNode<V>(key, value);
        node->next = head;
        buckets[bucketIndex] = node;
        count++;
        double loadFactor = (1.0*count)/numBuckets;  //checking loadFactor and rehashing
        if(loadFactor > 0.7){
            rehash();
        }
    }

    V remove(string key){
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex];
        MapNode<V>* prev = NULL;
        while(head != NULL){
            if(head->key == key){
                if(prev == NULL){
                    buckets[bucketIndex] = head->next;
                }else{
                    prev->next = head->next;
                }
                V value = head->value;
                head->next = NULL;
                delete head;
                count--;
                return value;
            }
            prev = head;
            head = head->next;
        }
        return 0;
    }

};

//driver code
int main(){
    Map<int> map;
    for(int i = 0l i < 10; i++){
        char c = '0' + i;
        string key = "abc";
        key += c;
        int value = i + 1;
        map.insert(key, value);
    }
}