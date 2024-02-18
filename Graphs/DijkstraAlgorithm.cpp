#include <iostream>
#include <climits>
using namespace std;

int findMinVertex(bool *visited, int *distance, int v){
    int vertex = -1;
    for(int i = 0; i < v; i++){
        if(!visited[i] && (vertex == -1 || distance[i] < distance[vertex])){
            vertex = i;
        }
    }
    return vertex;
}

void dijkstraAlgorithm(int **edges, bool *visited, int *distance, int v){
    distance[0] = 0;

    for(int i = 0; i < v; i++){
        int currentVertex = findMinVertex(visited, distance, v);
        visited[currentVertex] = true;
        for(int j = 0; j < v; j++){
            if(edges[currentVertex][j] != 0 && !visited[j]){
                int dist = distance[currentVertex] + edges[currentVertex][j];
                if (dist < distance[j]) {
                  distance[j] = dist;
                }
            }
        }
    }

    for(int i =0; i < v; i++){
        cout << i << " " << distance[i] << "\n";
    }
}

int main() {
    int n, e;
    cin >> n >> e;
    int **edges = new int*[n];
    for(int i = 0; i < n; i++){
        edges[i] = new int[n];
    }

    for(int i = 0; i < e; i++){
        int f, s, weight;
        cin >> f >> s >> weight;
        edges[s][f] = edges[f][s] = weight;
    }

    bool *visited = new bool[n];
    int *distance = new int[n];
    for(int i = 0; i < n; i++){
        distance[i] = INT_MAX;
        visited[i] = false;
    }

    dijkstraAlgorithm(edges, visited, distance, n);

    for(int i = 0; i < n; i++){
        delete[] edges[i];
    }

    delete[] visited;
    delete[] distance;

    return 0;
}