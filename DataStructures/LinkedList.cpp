#include <iostream>
using namespace std;

class Node{
    
    public:
    int data;
    Node *next;

    Node(int data){
        this -> data = data;
        next = NULL; 
    }
};

int main(){
    //Statically
    Node n1(1);
    Node n2(2);
    
    return 0;
}