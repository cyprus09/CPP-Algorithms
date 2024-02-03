#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

int editDistanceHelper(string s1, string s2, vector<vector<int>> &output) {
    int m = s1.size();
    int n = s2.size();

    if (m == 0) {
        return n;
    }
    if (n == 0) {
        return m;
    }

    if (output[m][n] != -1) {
        return output[m][n];
    }

    int ans;
    if (s1[0] == s2[0]) {
        ans = editDistanceHelper(s1.substr(1), s2.substr(1), output);
    } else {
        int a = editDistanceHelper(s1, s2.substr(1), output);
        int b = editDistanceHelper(s1.substr(1), s2, output);
        int c = editDistanceHelper(s1.substr(1), s2.substr(1), output);
        ans = 1 + min(a, min(b, c));
    }

    output[m][n] = ans;
    return ans;
}

int main()
{
	string s1;
	string s2;

	cin >> s1;
	cin >> s2;

	cout << editDistance(s1, s2) << endl;
}

int editDistance(string s1, string s2) {
    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> output(m + 1, vector<int>(n + 1, -1));
    return editDistanceHelper(s1, s2, output);
}
