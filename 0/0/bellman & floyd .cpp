#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

// Bellman-Ford Algorithm
bool bellmanFord(int n, vector<vector<int>> &edges, int src, vector<int> &distances)
{
    distances.assign(n, INF);
    distances[src] = 0;

    for (int i = 0; i < n - 1; ++i)
    {
        for (auto &edge : edges)
        {
            int u = edge[0], v = edge[1], w = edge[2];
            if (distances[u] != INF && distances[u] + w < distances[v])
            {
                distances[v] = distances[u] + w;
            }
        }
    }

    // Check for negative weight cycles
    for (auto &edge : edges)
    {
        int u = edge[0], v = edge[1], w = edge[2];
        if (distances[u] != INF && distances[u] + w < distances[v])
        {
            return false; // Negative cycle detected
        }
    }

    return true;
}

// Floyd-Warshall Algorithm
void floydWarshall(int n, vector<vector<int>> &graph, vector<vector<int>> &distances)
{
    distances = graph;

    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (distances[i][k] < INF && distances[k][j] < INF)
                {
                    distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j]);
                }
            }
        }
    }
}

int main()
{
    int vertices, edgesCount;
    cout << "Enter number of vertices and edges: ";
    cin >> vertices >> edgesCount;

    vector<vector<int>> edges;
    vector<vector<int>> graph(vertices, vector<int>(vertices, INF));

    for (int i = 0; i < vertices; ++i)
    {
        graph[i][i] = 0;
    }

    cout << "Enter edges (u, v, weight):\n";
    for (int i = 0; i < edgesCount; ++i)
    {
        int u, v, weight;
        cin >> u >> v >> weight;
        edges.push_back({u, v, weight});
        graph[u][v] = weight;
    }

    // Bellman-Ford
    int source;
    cout << "Enter source vertex for Bellman-Ford: ";
    cin >> source;

    vector<int> bfDistances;
    if (bellmanFord(vertices, edges, source, bfDistances))
    {
        cout << "\nBellman-Ford Shortest Paths from Node " << source << ":\n";
        for (int i = 0; i < vertices; ++i)
        {
            cout << "To " << i << ": " << (bfDistances[i] == INF ? "INF" : to_string(bfDistances[i])) << '\n';
        }
    }
    else
    {
        cout << "\nNegative weight cycle detected in Bellman-Ford Algorithm.\n";
    }

    // Floyd-Warshall
    vector<vector<int>> fwDistances;
    floydWarshall(vertices, graph, fwDistances);
    cout << "\nFloyd-Warshall All-Pairs Shortest Paths:\n";
    for (int i = 0; i < vertices; ++i)
    {
        for (int j = 0; j < vertices; ++j)
        {
            cout << (fwDistances[i][j] == INF ? "INF" : to_string(fwDistances[i][j])) << " ";
        }
        cout << '\n';
    }

    return 0;
}

