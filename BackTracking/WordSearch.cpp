#include<bits/stdc++.h>

using namespace std;

//method - 1
bool dfs(int x, int y, int n, int m, vector<vector<char>> &board, string &word, int k){
    if(k == word.size()){
        return true;
    }else if(x < 0 || x == n || y < 0 || y == m || board[x][y] == '#' || board[x][y] != word[k]){
        return false;
    }else{
        char temp = board[x][y];
        board[x][y] == '#';
        bool dir1 = dfs(x - 1, y, n, m, board, word, k + 1);
        bool dir2 = dfs(x + 1, y, n, m, board, word, k + 1);
        bool dir3 = dfs(x, y - 1, n, m, board, word, k + 1);
        bool dir4 = dfs(x, y + 1, n, m, board, word, k + 1);
        board[x][y] = temp;
        return dir1 || dir2 || dir3 || dir4;
    }
}

bool present(vector<vector<char>> &board, string &word, int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == word[0] && dfs(i, j, n, m, board, word, 0)){
                return true;
            }
        }
    }

    return false;
}

//method - 2
bool isValid(int x, int y, int m, int n, char ch, vector<vector<bool>> &visited, vector<vector<char>> &board){
    if(x < 0 || x >= n || y < 0 || y >= m){
        return false;
    }
    if(visited[x][y] || board[x][y] != ch){
        return false;
    }

    return true;
}

void searchWord(int x, int y, int m, int n, const string &word, vector<vector<bool>> &visited, vector<vector<char>> &board, bool &found){
    if(word.size() == 1){
        found = true;
        return;
    }

    visited[x][y] = true;

    if(isValid(x - 1, y, m, n, word[1], visited, board) && !found){
        searchWord(x - 1, y, m, n, word.substr(1), visited, board, found);
    }
    if(isValid(x + 1, y, m, n, word[1], visited, board) && !found){
        searchWord(x + 1, y, m, n, word.substr(1), visited, board, found);
    }
    if(isValid(x, y - 1, m, n, word[1], visited, board) && !found){
        searchWord(x, y - 1, m, n, word.substr(1), visited, board, found);
    }
    if(isValid(x, y + 1, m, n, word[1], visited, board) && !found){
        searchWord(x, y + 1, m, n, word.substr(1), visited, board, found);
    }

    visited[x][y] = false;
}


bool present(vector<vector<char>> &board, string &word, int n, int m) {
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    bool found = false;

    for (int i = 0; i < n && !found; i++) {
        for (int j = 0; j < m && !found; j++) {
            searchWord(i, j, m, n, word, visited, board, found);
        }
    }

    return found;
}

class Runner
{
    string s;
    int n,m;
    vector<vector<char>> mat;

public:
    
    void takeInput()
    {
        cin >> s >> n >> m;
        mat = vector<vector<char>> (n,vector<char> (m));
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin >> mat[i][j];
    }
    void execute()
    {
        // make copy if vector
        auto cmat = mat;
        present(cmat,s,n,m);
    }
    void executeAndPrintOutput()
    {
        auto cmat = mat;
        if(present(cmat,s,n,m))cout << "true";
        else cout << "false";
    }
};

int main()
{
        Runner runner;
        runner.takeInput();
        runner.executeAndPrintOutput();   
    return 0;
    
}
