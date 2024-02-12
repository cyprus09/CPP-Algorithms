#include <iostream>
#include <vector>
using namespace std;

void printDFSPath(int **graph, int v, int v1, int v2, bool *visited, vector<int> &path) {
    visited[v1] = true;
    path.push_back(v1);

    if (v1 == v2) {
        for (int i = path.size() - 1; i >= 0; i--) {
            cout << path[i] << " ";
        }
        return;
    }

    for (int i = 0; i < v; i++) {
        if (graph[v1][i] == 1 && !visited[i]) {
            printDFSPath(graph, v, i, v2, visited, path);
        }
    }

    path.pop_back();
}

int main() {
    int v, e; 
    cin >> v >> e;

    int **edges = new int *[v];
    for (int i = 0; i < v; i++) {
        edges[i] = new int[v];
    }

    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        edges[u][v] = edges[v][u] = 1; 
    }

    int v1, v2;
    cin >> v1 >> v2;

    bool *visited = new bool[v];
    vector<int> path;

    printDFSPath(graph, v, v1, v2, visited, path);

    for (int i = 0; i < v; i++) {
        delete[] graph[i];
    }
    delete[] graph;
    delete[] visited;

    return 0;
}
