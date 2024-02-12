#include <iostream>
using namespace std;

void DFSPath(int **edges, int n, int v, bool *visited) {
    visited[v] = true;
    for (int i = 0; i < n; i++) {
        if (i == v) {
            continue;
        }
        if (edges[v][i] == 1 && !visited[i]) {
            DFSPath(edges, n, i, visited);
        }
    }
}

bool isConnected(int **edges, int n, int v) {
    bool *visited = new bool[n]();
    DFSPath(edges, n, v, visited);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            delete[] visited;
            return false;
        }
    }
    delete[] visited;
    return true;
}

int main() {
    int n, e;
    cin >> n >> e;

    int **edges = new int *[n];
    for (int i = 0; i < n; i++) {
        edges[i] = new int[n]();
    }

    for (int i = 0; i < e; i++) {
        int f, s;
        cin >> f >> s;
        edges[f][s] = edges[s][f] = 1;
    }

    if (isConnected(edges, n, 0)) {
        cout << "true";
    } else {
        cout << "false";
    }

    for (int i = 0; i < n; i++) {
        delete[] edges[i];
    }

    delete[] edges;

    return 0;
}