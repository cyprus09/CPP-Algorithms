#include <iostream>
#include <vector>
using namespace std;

void connectedComponentsHelper(int **edges, int n, int v, vector<int> &connected, bool *visited){
    visited[v] = true;

    for(int i = 0; i < n; i++){
        if(i == v){
            continue;
        }
        if(!visited[i] && edges[v][i] == 1){
            connectedComponentsHelper(edges, n, i, connected, visited);
            connected.push_back(i);
        }
    }
}

vector<vector<int>> connectedComponents(int **edges, int n){
    vector<vector<int>> output;
    bool *visited = new bool[n]();
    vector<int> connected;

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            connectedComponentsHelper(edges, n, i, connected, visited);
            connected.push_back(i);
            output.push_back(connected);
            connected.clear();
        }
    }
    delete[] visited;
    return output;
}

int main() {
    int n, e;
    cin >> n >> e;

    int **edges = new int*[n];
    for(int i = 0; i < n; i++){
        edges[i] = new int[n]();
    }

    for(int i = 0; i < e; i++){
        int f, s;
        cin >> f >> s;
        edges[f][s] = edges[s][f] = 1;
    }

    vector<vector<int>> output = connectedComponents(edges, n);

    for(int i = 0; i < output.size(); i++){
        for(int j = 0; j < output[i].size(); j++){
            cout << output[i][j] << " ";
        }
        cout << endl;
    }

     for (int i = 0; i < n; i++) {
        delete[] edges[i];
    }

    delete[] edges;

    return 0;
}