#include <bits/stdc++.h>
using namespace std;

void dijkstra(int start, vector<vector<pair<int, int>>> &adj)
{
    int l = adj.size();
    vector<bool> visited(l, false);
    vector<int> dist(l, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for (auto neighbour : adj[u])
        {
            int v = neighbour.first;
            int weight = neighbour.second;

           
            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

   
    for (int i = 0; i < l; i++)
    {     
            cout << i << "=" << dist[i] << endl;
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<pair<int, int>>> adj(n);

    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    int start;
    cin >> start;
    dijkstra(start, adj);
}
