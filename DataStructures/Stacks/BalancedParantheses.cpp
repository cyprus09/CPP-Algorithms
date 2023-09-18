#include <iostream>
#include <string>
using namespace std;

bool isBalanced(string expression) {
    
    stack<char> brackets;
   
    for(int i = 0; expression[i] != '\0'; i++){
        if(expression[i] == '('){
            brackets.push('(');
        } else if(expression[i] == ')'){
            if(brackets.empty()){
                return false;
            }
            brackets.pop();
        } else {
            continue;
        }
    } 
    return brackets.empty();  
}

int main() 
{
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}