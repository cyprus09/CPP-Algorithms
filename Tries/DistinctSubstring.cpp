#include <iostream>
#include <string>git 
using namespace std;

class TrieNode{
    public:
    TrieNode **children;
    bool isTerminal;

    TrieNode(){
        children = new TrieNode*[26];
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

int countDistinctSubstrings(string &s){
    TrieNode *head = new TrieNode();
    int count = 1;

    for(int i = 0; i < s.length(); i++){
        TrieNode *temp = head;
        for(int j = i; j < s.length(); j++){
            if(temp->children[s[j] - 'a'] == NULL){
                temp->children[s[j] - 'a'] = new TrieNode();
                temp->isTerminal = true;
                count++;
            }
            temp = temp->children[s[j] - 'a'];
        }
    }

    return count;
}