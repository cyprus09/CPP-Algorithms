#include<iostream>
#include <string>
using namespace std;

// bool checksequenece(char large[] , char*small) {

//     int length_large = strlen(large);
//     int length_small = strlen(small);
//     int j = 0;

//     for(int i = 0; i < length_large && j < length_small; i++){
//         if(small[j] == large[i]){
//             j++;
//         }
//     }
//     if(j == length_small){
//         return true;
//     }
//     return false;
// }

bool checkSequenceRecursive(char large[], char* small, int i, int j) {
    if (j == strlen(small)) {
        return true; 
    }
    if (i == strlen(large)) {
        return false;
    }
    if (small[j] == large[i]) {
        return checkSequenceRecursive(large, small, i + 1, j + 1);
    } else {
        return checkSequenceRecursive(large, small, i + 1, j);
    }
}
bool checksequenece(char large[] , char*small) {
    checkSequenceRecursive(large, small, 0, 0);
}

//counting number of subsequences
int subSequence(string input, string output[]){
    if(input.empty()){
        output[0] = '';
        return 1;
    }

    string smallString = input.substr(1);
    int smallOutputSize = subSequence(smallString, output);
    
    for(int i = 0; i < smallOutputSize; i++){
        output[i + smallOutputSize] = input[0] + output[i];
    }

    return 2 * smallOutputSize;
}

int main()
{
	char large[10000];
	char small[10000];
	cin>>large;
	cin>>small;
	bool x=checksequenece(large , small);

	if(x)
		cout<<"true";
	else
		cout<<"false";


    string input;
    cin >> input;
    
    string* output = new string[1000];
    
    int count = subSequence(input, output);

    for(int i = 0 ; i < count; i++){
        cout << output[i] << endl;
    }
}