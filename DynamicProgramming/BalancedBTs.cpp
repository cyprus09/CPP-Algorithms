#include <iostream>
using namespace std;

const long long mod = 1000000007;

//recursive approach
long long balancedBTs(int n) {
    if(n <= 1){
        return 1;
    }    
    long long x = balancedBTs(n - 1);
    long long y = balancedBTs(n - 2);

    return (x * x + 2 * x * y) % mod;
}

//bottom-down approach
long long balancedBTs_dp(int n) {
    long long *totalTrees = new long long[n + 1];

    totalTrees[0] = 1;
    totalTrees[1] = 1;

    for (int i = 2; i <= n; i++) {  
        long long x = totalTrees[i - 1] % mod, y = 0;

        if (i - 2 >= 0) {  
            y = totalTrees[i - 2] % mod;
        }

        totalTrees[i] = (x * x + 2 * x * y) % mod;
    }

    long long result = totalTrees[n] % mod;

    delete[] totalTrees;
    return result;
}


int main() {
    int n;
    cin >> n;
    cout << balancedBTs(n);
}