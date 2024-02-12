#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void printShortestPath(int **graph, int v, int v1, int v2) {
    queue<int> q;
    vector<int> predecessor(v, -1);
    bool *visited = new bool[v]();

    q.push(v1);
    visited[v1] = true;

    while (!q.empty()) {
        int currentVertex = q.front();
        q.pop();

        for (int i = 0; i < v; i++) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                q.push(i);
                visited[i] = true;
                predecessor[i] = currentVertex;

                if (i == v2) {
                    vector<int> path;
                    int vertex = v2;
                    while (vertex != -1) {
                        path.push_back(vertex);
                        vertex = predecessor[vertex];
                    }

                    for (int j = path.size() - 1; j >= 0; j--) {
                        cout << path[j] << " ";
                    }

                    delete[] visited;
                    return;
                }
            }
        }
    }

    cout << "No path found between " << v1 << " and " << v2 << endl;

    delete[] visited;
}

int main() {
    int v, e;
    cin >> v >> e;

    int **edges = new int *[v];
    for (int i = 0; i < v; i++) {
        edges[i] = new int[v]();
    }

    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        edges[u][v] = edges[v][u] = 1;
    }

    int v1, v2;
    cin >> v1 >> v2;

    printShortestPath(edges, v, v1, v2);

    for (int i = 0; i < v; i++) {
        delete[] edges[i];
    }
    delete[] edges;

    return 0;
}
