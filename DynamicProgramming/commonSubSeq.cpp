#include <bits/stdc++.h>
using namespace std;

//recursive approach
int lcs(string s, string t){
    if(s.size() == 0 || t.size() == 0){
        return 0;
    } 

    if(s[0] == t[0]){
        return 1 + lcs(s.substr(1), t.substr(1));
    }else{
        int a = lcs(s.substr(1), t);
        int b = lcs(s, t.substr(1));
        int c = lcs(s.substr(1), t.substr(1));
        return max(a, max(b, c));
    }
}

//memoisation
int lcs_mem(string s, string t, vector<vector<int>> &output){
    int m = s.size();
    int n = t.size();

    if(s.size() == 0 || t.size() == 0){
        return 0;
    } 

    if(output[m][n] != -1){
        return output[m][n];
    }

    int ans;
    if(s[0] == t[0]){
        ans = 1 + lcs_mem(s.substr(1), t.substr(1), output);
    }else{
        int a = lcs_mem(s.substr(1), t, output);
        int b = lcs_mem(s, t.substr(1), output);
        int c = lcs_mem(s.substr(1), t.substr(1));
        ans = max(a, max(b, c));
    }

    output[m][n] = ans;

    return output[m][n];
}

//bottom-down dp approach
int lcs_dp(string s, string t){
    int m = s.size();
    int n = t.size();
    int ** output = new int * [m + 1];
    for(int i = 0; i < m; i++){
        output[i] = new int[n + 1];
    }

    for(int i = 0; i <= m; i++){
        output[0][i] = 0;
    }
    for(int i = 1; i <= n; i++){
        output[i][0] = 0;
    }

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(s[] == t[]){
                output[i][j] = 1 + output[i - 1][j - 1];
            }else{
                int a = output[i - 1][j];
                int b = output[i][j - 1];
                int c = output[i - 1][j - 1];
                output[i][j] = max(a, max(b, c)) 
            }
        }
    }

    return output[m][n];
}

int main(){
    string s, t;
    cin >> s >> t;
    int m = s.size(), n = t.size();
    vector<vector<int>> output(m, vector<int>(n, -1));

    cout << lcs(s, t);
    cout << lcs_mem(s, t, output);

}