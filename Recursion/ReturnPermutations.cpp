#include <iostream>
#include <string>

using namespace std;

int return_permutations(string input, string output[]){
    if(input.length() == 0 || input.length() == 1){
        output[0] = input;
        return 1;
    }

    string smallerOutput[1000];
    int smallOutputSize = return_permutations(input.substr(1), smallerOutput);
    char firstChar = input[0];

    int k = 0;

    for(int i = 0; i < smallOutputSize; i++){
        for(int j = 0; j <= smallerOutput[i].length(); j++){
            output[k] = smallerOutput[i].substr(0, j) + firstChar + smallerOutput[i].substr(j);
            k++;
        }
    }

    return k;
}

int main(){
    string input;
    cin >> input;
    output[1000];
    for(int i = 0; i < return_permutations(input, output); i++){
        output[i] << endl;
    }
}