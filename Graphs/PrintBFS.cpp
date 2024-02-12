#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> getPathBFS(int **edges, bool *visited, int V1, int V2, int V) {
    if (V1 == V2) {
        vector<int> ans;
        ans.push_back(V1);
        visited[V1] = true;
        return ans;
    }

    queue<int> q;
    unordered_map<int, int> h;
    vector<int> ans;
    q.push(V1);
    visited[V1] = true;

    while (!q.empty()) {
        int first = q.front();
        q.pop();

        for (int i = 0; i < V; i++) {
            if (edges[first][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
                h[i] = first;

                if (i == V2) {
                    ans.push_back(i);

                    while (!ans.empty() && ans.back() != V1) {
                        int b = h[i];
                        ans.push_back(b);
                        i = b;
                    }
                    return ans;
                }
            }
        }
    }

    return vector<int>();
}

int main() {
    int V, E;
    cin >> V >> E;
    int **edges = new int*[V];
    
    for (int i = 0; i < V; i++) {
        edges[i] = new int[V]();
    }

    for (int i = 0; i < E; i++) {
        int sv, ev;
        cin >> sv >> ev;
        edges[sv][ev] = 1;
        edges[ev][sv] = 1;
    }

    int V1, V2;
    cin >> V1 >> V2;

    bool *visited = new bool[V]();

    vector<int> ans = getPathBFS(edges, visited, V1, V2, V);

    for (int elem : ans) {
        cout << elem << " ";
    }

    for (int i = 0; i < V; i++) {
        delete[] edges[i];
    }

    delete[] edges;
    delete[] visited;

    return 0;
}