#include <bits/stdc++.h>
using namespace std;

//brute-force recursive approach
int minCostPathHelper(int **input, int m, int n, int i, int j){
    if(i > m || j > n){
        return INT_MAX;
    }
    //base case
    if(i == m - 1 && j == n - 1){
        return input[i][j];
    }
    //recursive calls
    int x = minCostPathHelper(input, m, n, i + 1, j);
    int y = minCostPathHelper(input, m, n, i + 1, j + 1);
    int z = minCostPathHelper(input, m, n, i, j + 1);

    //small calculation
    int ans = input[i][j] + min(x, min(y, z));

    return ans;
}


int minCostPath_Rec(int **input, int m, int n){
    return minCostPathHelper(input, m, n, 0, 0);
}

//memoisation approach
int minCostPathHelper(int **input, int m, int n, int i, int j, vector<vector<int>> &output) {
    if (i >= m || j >= n) {
        return INT_MAX;
    }

    // Base case
    if (i == m - 1 && j == n - 1) {
        return input[i][j];
    }

    if (output[i][j] != -1) {
        return output[i][j];
    }

    int x = minCostPathHelper(input, m, n, i + 1, j, output);
    int y = minCostPathHelper(input, m, n, i + 1, j + 1, output);
    int z = minCostPathHelper(input, m, n, i, j + 1, output);

    output[i][j] = input[i][j] + min(x, min(y, z));

    return output[i][j];
}

int minCostPath_Mem(int **input, int m, int n) {
    vector<vector<int>> output(m, vector<int>(n, -1));
    return minCostPathHelper(input, m, n, 0, 0, output);
}

//dp-approach
int minCostPath_DP(int **input, int m, int n){
    int **storage = new int*[m];
    for(int i = 0; i < m; i++){
        storage[i] = new int[n];
    }
    storage[m - 1][n - 1] = input[m - 1][n - 1];

    for(int j = n - 2; j >= 0; j--){
        storage[m - 1][j] = storage[m - 1][j + 1] + input[m - 1][j];
    }

    for(int i = m - 2; i >= 0; i--){
        storage[i][n - 1] = storage[i + 1][n - 1] + input[i][n - 1];
    }
    for(int i = m - 2; i >= 0; i--){
        for(int j = n - 2; j >= 0; j--){
            storage[i][j] = input[i][j] + min(storage[i][j + 1], min(storage[i + 1][j + 1], storage[i + 1][j]));
        }
    }

    int result = storage[0][0];

    for(int i = 0; i < m; i++){
        delete [] storage[i];
    }
    delete [] storage;
    
    return result;
}

int main()
{
	int **arr, n, m;
	cin >> n >> m;
	arr = new int *[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << minCostPath(arr, n, m) << endl;
}