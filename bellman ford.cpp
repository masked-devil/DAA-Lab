#include<iostream>
#include<limits.h>

using namespace std;

struct Edge {
    int source, destination, weight;
};

void bellmanFord(Edge edges[], int V, int E, int source) {
    int distance[V];
    for(int i = 0; i < V; i++) {
        distance[i] = INT_MAX;
    }
    distance[source] = 0;

    for(int i = 0; i < V - 1; i++) {
        for(int j = 0; j < E; j++) {
            int u = edges[j].source;
            int v = edges[j].destination;
            int w = edges[j].weight;
            if(distance[u] != INT_MAX && distance[u] + w < distance[v])
                distance[v] = distance[u] + w;
        }
    }

    // Check for negative weight cycles
    for(int i = 0; i < E; i++) {
        int u = edges[i].source;
        int v = edges[i].destination;
        int w = edges[i].weight;
        if(distance[u] != INT_MAX && distance[u] + w < distance[v]) {
            cout << "Graph contains negative weight cycle." << endl;
            return;
        }
    }

    // Print the shortest distances
    cout << "Shortest distances from source vertex " << source << ":\n";
    for(int i = 0; i < V; i++) {
        cout << "Vertex " << i << ": " << distance[i] << endl;
    }
}

int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    Edge edges[E];
    cout << "Enter source, destination, and weight for each edge:" << endl;
    for(int i = 0; i < E; i++) {
        cin >> edges[i].source >> edges[i].destination >> edges[i].weight;
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    bellmanFord(edges, V, E, source);

    return 0;
}
