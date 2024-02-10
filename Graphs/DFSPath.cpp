#include <iostream>
#include <vector>
using namespace std;

void printDFSPath(int **graph, int n, int v1, int v2, bool *visited, vector<int> &path) {
    visited[v1] = true;
    path.push_back(v1);

    if (v1 == v2) {
        for (int i = path.size() - 1; i >= 0; i--) {
            cout << path[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (graph[v1][i] == 1 && !visited[i]) {
            printDFSPath(graph, n, i, v2, visited, path);
        }
    }

    path.pop_back();
}

int main() {
    int n, e; 
    cin >> n >> e;

    int **graph = new int *[n];
    for (int i = 0; i < n; i++) {
        graph[i] = new int[n]();
    }

    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = graph[v][u] = 1; 
    }

    int v1, v2;
    cin >> v1 >> v2;

    bool *visited = new bool[n]();
    vector<int> path;

    printDFSPath(graph, n, v1, v2, visited, path);

    for (int i = 0; i < n; i++) {
        delete[] graph[i];
    }
    delete[] graph;
    delete[] visited;

    return 0;
}
