#include <iostream>
#include <queue>

using namespace std;

void print(int **edges, int n, int sv, bool *visited){
    queue<int> graphNodes;
    graphNodes.push(sv);
    visited[sv] = true;

    while(!graphNodes.empty()){
        int currentVertex = graphNodes.front();
        cout << currentVertex << " ";
        graphNodes.pop();

        for(int i = 0 ; i < n; i++){
          if (visited[i] == false && edges[currentVertex][i] == 1) {
            graphNodes.push(i);
            visited[i] = true;
          }
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;
    int **edges = new int*[n];
    for(int i = 0; i < n; i++){
        edges[i] = new int[n];
        for(int j = 0; j < n; j++){
            edges[i][j] = 0;
        }
    }

    for(int i = 0; i < e; i++){
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    } 

    bool *visited = new bool[n];
    for(int i = 0; i < n; i++){
        visited[i] = false;
    }

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            print(edges, n, i, visited);        
            }
    }

    for(int i = 0; i < n; i++){
        delete[] edges[i];
    }

    delete[] edges;
    delete[] visited;

    return 0;
}