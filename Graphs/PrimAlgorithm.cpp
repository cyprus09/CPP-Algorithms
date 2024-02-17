#include <iostream>
#include <climits>
using namespace std;

int findMinVertex(bool *visited, int *weights, int v){
    int vertex = -1;
    for(int i = 0; i < v; i++){
        if(!visited[i] && (vertex == -1 || weights[i] < weights[vertex]))
            vertex = i;
    }
    return vertex;
}

void primAlgorithm(int **edges, bool *visited, int *weights, int *parents, int v){
    parents[0] = -1;
    weights[0] = 0;

    for(int i = 0; i < (v - 1); i++){
        int vertex = findMinVertex(visited, weights, v);
        visited[vertex] = true;
        for(int j = 0; j < v; j++){
            if(edges[vertex][j] && !visited[j] && edges[vertex][j] < weights[j]){
                parents[j] = vertex;
                weights[j] = edges[vertex][j];
            }
        }

    }

    for(int i = 1; i < v; i++){
        cout << min(i, parents[i]) << " " << max(i, parents[i]) << " " << weights[i] << "\n";
    }
}

int main() {
    int v, e;
    cin >> v >> e;
    int **edges = new int *[v];
    for (int i = 0; i < v; i++)
    {
        edges[i] = new int[v];
        for (int j = 0; j < v; j++)
            edges[i][j] = 0;
    }

    for (int i = 0; i < e; i++)
    {
        int start, end, weight;
        cin >> start >> end >> weight;
        edges[start][end] = weight;
        edges[end][start] = weight;
    }

    bool *visited = new bool[v];
    int *weights = new int[v];
    int *parents = new int[v];
    for(int i = 0; i < v; i++){
        weights[i] = INT_MAX;
        visited[i] = false;
    }

    primAlgorithm(edges, visited, weights, parents, v);

    for(int i = 0; i < n; i++){
        delete[] edges[i];
    }

    delete[] edges;
    delete[] visited;
    delete[] weights;
    delete[] parents; 

    return 0;
}