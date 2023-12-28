#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

class Node{
    char ch;
    int freq;
    Node *left, *right;

    Node(char ch, int freq, Node* left, Node *right){
        this->ch = ch;
        this->freq = freq;
        this->left = left;
        this->right = right;
    }
};

class comp(){
    bool operator()(Node* l, Node* r){
        return l->freq > r->freq;
    }
};

//storing huffman codes in an unordered hashmap and traversing
void encode(Node* root, string str, unordered_map<char, string> &huffmanCode){
    if(root == NULL){
        return;
    }

    if(!root->left && !root->right){
        huffmanCode[root->ch] = str;
    }

    encode(root->left, str + '0', huffmanCode);
    encode(root->right, str + '1', huffmanCode);
}

//decoding the huffman tree from the hashmap
void decode(Node* root, int &index, string str){
    if(root == NULL){
        return;
    }
    if(!root->left && !root->right){
        cout << root->ch;
        return;
    }
    index++;

    if(str[index] == '0'){
        decode(root->left, index, str);
    }else{
        decode(root->right, index, str);
    }
}

