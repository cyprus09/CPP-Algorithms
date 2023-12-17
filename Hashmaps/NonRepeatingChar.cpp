#include <unordered_map> 
#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

char firstNonRepeatingCharacter(string str) {
  unordered_map<int, char> charCount;
  for(char ch : str){
    charCount[ch]++;
  }

  for(char ch : str){
    if(charCount[ch] == 1){
      return ch;
    }
  }

  return '\0';
}

class Runner
{
    int t;

    
    vector<string> arr;


public:
    void takeInput()
    {

 cin >> t;
        arr.resize(t);
        

        for (int tc = 0; tc < t; tc++)
        {
       cin>>arr[tc];

        }

        
    }

    void execute()
    {
         vector<string> arrCopy = arr;
        for (int i=0;i<t;i++){
            firstNonRepeatingCharacter(arrCopy[i]);
        }
    }


    void executeAndPrintOutput()
    {
        for (int tt=0;tt<t;tt++){
            char v=firstNonRepeatingCharacter(arr[tt]);
            {
              cout<<v;         
            }
            cout<<"\n";
        }
    }
};

int main()
{

    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();

    return 0;
}
