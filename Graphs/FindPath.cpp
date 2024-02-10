#include <iostream>
#include <queue>

using namespace std;

bool findPath(int **edges, int n, int a, int b) {
    queue<int> pathNodes;
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    pathNodes.push(a);
    visited[a] = true;

    while (!pathNodes.empty()) {
        int currentVertex = pathNodes.front();
        pathNodes.pop();

        if (currentVertex == b) {
            delete[] visited;
            return true;
        }

        for (int i = 0; i < n; i++) {
            if (visited[i] == false && edges[currentVertex][i] == 1) {
                pathNodes.push(i);
                visited[i] = true;
            }
        }
    }
    delete[] visited;
    return false;
}

int main() {
    int v, e;
    cin >> v >> e;

    int **edges = new int *[v];
    for (int i = 0; i < v; i++) {
        edges[i] = new int[v];
        for (int j = 0; j < v; j++) {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++) {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    int v1, v2;
    cin >> v1 >> v2;

    if(findPath(edges, v, 0, v1, v2) == true){
        cout << "true";
    }else{
        cout << "false";
    };

    for (int i = 0; i < v; i++) {
        delete[] edges[i];
    }
    delete[] edges;

    return 0;
}
