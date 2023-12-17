#include <bits/stdc++.h> 
#include <iostream>
#include <cstring>
using namespace std;

bool isPermutation(char input1[], char input2[]) {
    int sum1 = 0, sum2 = 0;

    for(int i = 0; i < strlen(input1); i++){
        int character = input1[i];
        sum1 += character;
    }

    for(int i = 0; i < strlen(input2); i++){
        int character = input2[i];
        sum2 += character;
    }

    return sum1 == sum2;
}

int main() {
    int size = 1e6;
    char str1[size];
    char str2[size];
    cin >> str1 >> str2;
    cout << (isPermutation(str1, str2) ? "true" : "false");
}