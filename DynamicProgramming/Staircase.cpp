#include<bits/stdc++.h>
using namespace std;

const long long mod = 1000000007;

long long stairsCount(int n) {
   
   long long *stairs = new long long[n + 1];

    stairs[0] = 1;
    stairs[1] = 1;
    stairs[2] = 2;

		for(int i = 3 ;i <= n; i++) {
			long long step2 = 0, step3 = 0;
			long long step1 = stairs[i - 1];

			if(i - 2 >= 0)
			 step2 = stairs[i - 2] % mod;
			if(i - 3 >= 0)
			 step3 = stairs[i - 3] % mod;
			stairs[i] = step1 + step2 + step3;
		}
		long long result = stairs[n] % mod;
        delete[] stairs;

        return result;
}


int main()
{
    int T;
    cin >> T;

    while(T--){
        int N;
        cin >> N;
        cout << stairsCount(N);
        cout << endl;
    }

    return 0;
}