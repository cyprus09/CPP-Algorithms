#include <bits/stdc++.h>
using namespace std;

int minCount(int n){
	int *squareCount = new int[n + 1];

    squareCount[0] = 0;
    squareCount[1] = 1;
    squareCount[2] = 2;

    for(int i = 3; i <= n; i++){
        int ans = i;
        for(int j = 1; j <= sqrt(i); j++){
            ans = min(ans, squareCount[i - j * j] + 1);
        }
        squareCount[i] = ans;
    }
    int result = squareCount[n];
    delete[] squareCount;

    return result;
}

int main()
{
	int n;
	cin >> n;
	cout << minCount(n);
}