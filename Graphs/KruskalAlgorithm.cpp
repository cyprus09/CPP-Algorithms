#include <iostream>
#include <algorithm>
using namespace std;

class Edge{
    public:
    long v1, v2, weight;
};

bool compareEdges(Edge e1, Edge e2) {
    return e1.weight < e2.weight;
}

long unionFind(long *parent, long v){
    if(parent[v] == v) {
			return v;
		}
    return unionFind(parent, parent[v]);
}

void kruskalAlgorithm(Edge *input, long V){
    Edge *output = new Edge[V - 1];

    long *parent = new long[V];
    for(long i = 0; i < V; i++){
        parent[i] = i;
    }

    long count = 0, i = 0;
    while(count < (V - 1)){
        long parentSource = unionFind(parent, input[i].v1);
        long parentDest = unionFind(parent, input[i].v2);
        if(parentDest != parentSource){
            output[count] = input[i];
            parent[parentSource] = parentDest;
            count++;
        }
        i++;
    }

   for (long i = 0; i < (V - 1); i++) {
        cout << min(output[i].v1, output[i].v2) << " " << max(output[i].v1, output[i].v2) << " " << output[i].weight << "\n";
    }

    delete[] output;
    delete[] parent;
}

int main() {
    long V, E;
    cin >> V >> E;

    Edge *input = new Edge[E];
    for(long i = 0; i < E; i++){
        long f, s, weight;
        cin >> input[i].v1 >> input[i].v2 >> input[i].weight;
    }

    sort(input, input + E, compareEdges);
    kruskalAlgorithm(input, V);

    delete[] input;

    return 0;
}