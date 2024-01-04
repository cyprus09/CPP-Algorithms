#include <iostream>
#include <string>

using namespace std;

int keypad(int num, string output[]){
    
    if(num == 0 || num == 1){
        output[0] = "";
        return 1;
    }
    
    int lastDigit = num%10;
    smallNum = num/10;
    int smalloutputsize = keypad(smallNum, output);
    
    string input;
    switch(lastDigit){
        case 2: input = "abc";
            break;
        case 3: input = "def";
            break;
        case 4: input = "ghi";
            break;
        case 5: input = "jkl";
            break;
        case 6: input = "mno";
            break;
        case 7: input = "pqrs";
            break;
        case 8: input = "tuv";
            break;
        case 9: input = "wxyz";
            break;       
    }

    int ans_size=smalloutputsize*(input.size());
    string temp[ans_size];
    int idx=0;
    
    for(int i=0; i < smalloutputsize; i++){
        for(int j=0; j < input.size(); j++){
            temp[idx] = output[i]+input[j];
            idx++;
        }
        
    }

    for(int i=0; i<ans_size; i++){
        output[i] = temp[i];
    }
    
    return ans_size;
}

/*
method 2

void printKeypadHelper(int num, string outputSoFar, string keypadMapping[]) {
    if (num == 0) {
        cout << outputSoFar << endl;
        return;
    }

    int lastDigit = num % 10;

    string currentString = keypadMapping[lastDigit - 2];

    for (char ch : currentString) {
        string newOutput = ch + outputSoFar;

        printKeypadHelper(num / 10, newOutput, keypadMapping);
    }
}

void printKeypad(int num) {  
    string keypadMapping[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    printKeypadHelper(num, "", keypadMapping);
}

method 3

*/
int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}