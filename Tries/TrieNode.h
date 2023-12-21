#include <iostream>

template <Typename T>
class TrieNode{
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data){
        this->data = data;
        children = new TrieNode*[26];
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie{
    TrieNode* root;

    public:
    Trie(){
        root = new TrieNode('\0');
    }

    void insertWord(TrieNode* root, string word){
        if(word.size == 0){
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode *child;
        if(root->children[index] != NULL){
            child = root->children[index];
        }else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertWord(child, word.substr(1));
    }

    void insertWord(string word){
        insertWord(root, word);
    }

    bool search(string word) {
        TrieNode* temp = root;

        for(int i = 0; word[i] != '\0'; i++){
            int index = word[i] - 'a';
            if (temp->children[index] == NULL) {
                return 0;
            }
            temp = temp->children[index];            
        }

        if(temp != NULL && temp->isTerminal == true){
            return true;
        }
        
        return false;
    }
};