#include <bits/stdc++.h>
using namespace std;

//brute-force recursive method
int countMinStepsToOne(int n){
	if(n == 1){
		return 0;
	}

	int num_minus1 = countMinStepsToOne(n - 1);
	int num_by2 = (n % 2 == 0) ? countMinStepsToOne(n/2) : INT_MAX;
	int num_by3 = (n % 3 == 0) ? countMinStepsToOne(n/3) : INT_MAX;

	int ans = 1 + min(num_minus1, (num_by2, num_by3));

	return ans;
}

//memoisation method
unordered_map<int, int> memo;

int countMinStepsToOne(int n) {
    if (n == 1) {
        return 0;
    }

    // Check if result for current 'n' is already memoized
    if (memo.find(n) != memo.end()) {
        return memo[n];
    }

    int num_minus1 = countMinStepsToOne(n - 1);
    int num_by2 = (n % 2 == 0) ? countMinStepsToOne(n / 2) : INT_MAX;
    int num_by3 = (n % 3 == 0) ? countMinStepsToOne(n / 3) : INT_MAX;

    int ans = 1 + std::min(num_minus1, std::min(num_by2, num_by3));

    // Memoize the result for current 'n'
    memo[n] = ans;

    return ans;
}

//dp method
int countStepsToOne(int n){
    int *ans= new int[n+1];
    
    ans[1]=0;
    
    for(int i=2; i < n + 1; i++){
        
        int subtractOne = ans[i - 1];
        int divideByTwo = INT_MAX;
        int divideByThree = INT_MAX;

        if(i%2==0){ 
            divideByTwo = ans[i/2]; 
        }
        
        if(i%3==0){ 
            divideByThree = ans[i/3]; 
        }

        ans[i] = 1 + min(subtractOne, min(divideByThree, divideByTwo));
    }
    int result = ans[n];
    delete[] ans;
    
    return result;
}

int main()
{
	int n;
	cin >> n;
	cout << countMinStepsToOne(n);
}