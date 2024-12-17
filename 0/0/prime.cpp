#include <bits/stdc++.h>
using namespace std;

// Structure to represent a weighted edge
struct Edge {
    int node, weight;
    Edge(int n, int w) : node(n), weight(w) {}
};

// Custom comparator for the priority queue
struct Compare {
    bool operator()(Edge a, Edge b) {
        return a.weight > b.weight;
    }
};

void primMST(int vertices, vector<vector<Edge>>& adjList) {
    vector<bool> visited(vertices, false);
    priority_queue<Edge, vector<Edge>, Compare> pq;

    int startNode = 0; // Start from the first node
    pq.push(Edge(startNode, 0));
    int totalWeight = 0;

    cout << "Prim's MST Edges:\n";
    while (!pq.empty()) {
        Edge current = pq.top();
        pq.pop();

        int node = current.node;
        if (visited[node]) continue;

        visited[node] = true;
        totalWeight += current.weight;

        if (current.weight != 0) {
            cout << "Edge included: " << node << " - Weight: " << current.weight << "\n";
        }

        for (Edge neighbor : adjList[node]) {
            if (!visited[neighbor.node]) {
                pq.push(neighbor);
            }
        }
    }

    cout << "Total Weight of MST (Prim's): " << totalWeight << "\n";
}

int main() {
    cout<<"Enter the number of nodes and edges: ";
    int vertices, edges;
    cin >> vertices >> edges;

    vector<vector<Edge>> adjList(vertices);
    cout<<"Enter Connected nodes and their weights: ";
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back(Edge(v, w));
        adjList[v].push_back(Edge(u, w));
    }

    primMST(vertices, adjList);
    return 0;
}
