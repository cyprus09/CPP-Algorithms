#include <iostream>
#include <vector>
#include <bits/stdc++.h> 

using namespace std;

/* Method - 1 
int cell[101][101]; 
int vis[101][101];
int n;

bool isValid(int x, int y){

    if(x < 1 || x > n || y < 1 || y > n){
        return false;
    }
    if(cell[x][y] == 0 || vis[x][y] == 1){
        return false
    }
    return true;

}

void printSolution(){
    for(int i = 0; i <= n; i++){
        for(int j = 1; j <= n;j++){
            cout << vis[i][j] << " ";
        }
        cout << endl;
    } 
}

void searchMaze(int x, int y){
    vis[x][y] = 1;
    if(x == n && y == n){
        printSolution();
        vis[x][y] = 0;
        return;
    }
    if(isValid(x - 1, y)) searchMaze(x - 1, y);
    if(isValid(x + 1, y)) searchMaze(x + 1, y);
    if(isValid(x, y - 1)) searchMaze(x, y - 1);
    if(isValid(x, y + 1)) searchMaze(x, y + 1);
} */

// Method - 2

bool isValid(int x, int y, int N, const vector<vector<int>>& maze, vector<vector<bool>>& visited) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1 && !visited[x][y]);
}

void findPaths(int x, int y, int N, const vector<vector<int>>& maze, vector<vector<bool>>& visited, string& path, vector<string>& result) {
    if (x == N - 1 && y == N - 1) {
        result.push_back(path);
        return;
    }

    visited[x][y] = true;

    if (isValid(x, y - 1, N, maze, visited)) {
        path.push_back('U');
        findPaths(x, y - 1, N, maze, visited, path, result);
        path.pop_back();
    }
    if (isValid(x, y + 1, N, maze, visited)) {
        path.push_back('D');
        findPaths(x, y + 1, N, maze, visited, path, result);
        path.pop_back();
    }
    if (isValid(x - 1, y, N, maze, visited)) {
        path.push_back('L');
        findPaths(x - 1, y, N, maze, visited, path, result);
        path.pop_back();
    }
    if (isValid(x + 1, y, N, maze, visited)) {
        path.push_back('R');
        findPaths(x + 1, y, N, maze, visited, path, result);
        path.pop_back();
    }

    visited[x][y] = false;
}

vector<string> searchMaze(vector<vector<int>>& arr, int n) {
    vector<string> result;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    string path;

    findPaths(0, 0, n, arr, visited, path, result);

    return result;
}

class Runner {
    int t;
    vector<vector<int>> arr;

public:
    void takeInput() {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            arr.push_back(vector<int>());
            for(int j=0;j<n;j++)
            {
                int x;
                cin>>x;
                arr[i].push_back(x);
            }
        }
    }

    void execute() {
        vector<vector<int> > arrCopy = arr;

        vector<string> ans= searchMaze(arrCopy, arrCopy.size());
    }

    void executeAndPrintOutput() {
        vector<string> ans = searchMaze(arr,arr.size());
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
};

int main() {

    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();
    return 0;
}