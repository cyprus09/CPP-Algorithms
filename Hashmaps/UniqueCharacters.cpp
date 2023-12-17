#include <unordered_map>
#include <iostream>
#include <string>
using namespace std;

string uniqueChar(string str) {
	unordered_map<char, int> characters;
	string newString = "";

	for(int i = 0; i < str.length(); i++){
		char element = str[i];
		if(characters.count(element) > 0){
			characters[element] += 1;
		}else{
			newString += element;
			characters[element] = 1;
		}
	}

	return newString;
}

int main() {
    string str;
    cin >> str;
    cout << uniqueChar(str);
}
