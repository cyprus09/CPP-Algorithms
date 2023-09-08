#include <iostream>
using namespace std;

bool splitArray(int *input, int size) {
    int sumGroup1 = 0;
    int sumGroup2 = 0;

    for(int i = 0; i < size; i++){
        if(input[i]%5 == 0){
            sumGroup1 += input[i];
        }else if(input[i]%3 == 0 && input[i]%5 != 5){
            sumGroup1 += input[i];
        }else{
            sumGroup1 += input[i];
            sumGroup2 += input[i];
        }
    }

    if(sumGroup1 != sumGroup2){
        return false;
    }
    return true;
}

int main() {

	int size;
	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	
    if(splitArray(input, size)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

	
	return 0;

}