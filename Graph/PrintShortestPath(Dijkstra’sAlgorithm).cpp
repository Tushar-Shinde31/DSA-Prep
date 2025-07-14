#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        // Step 1: Create adjacency list for an undirected weighted graph
        // Each entry: node -> list of {neighbor, edge_weight}
        vector<pair<int, int>> adj[n + 1];  // 1-based indexing
        for (auto it : edges)
        {
            int u = it[0], v = it[1], w = it[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});  // since the graph is undirected
        }

        // Step 2: Set up priority queue and distance/parent arrays
        // Priority queue stores: {distance_from_source, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> dist(n + 1, 1e9);     // Distance from node 1 to all nodes, initially INF
        vector<int> parent(n + 1);        // Stores the parent (previous node) of each node in path

        for (int i = 1; i <= n; i++)
            parent[i] = i;  // Initially, every node is its own parent

        dist[1] = 0;        // Distance to source node is 0
        pq.push({0, 1});    // Start from node 1

        // Step 3: Standard Dijkstra’s Algorithm
        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int dis = it.first;

            // Traverse all adjacent nodes
            for (auto edge : adj[node])
            {
                int adjNode = edge.first;
                int edgeWeight = edge.second;

                // If new path to adjNode is shorter, update it
                if (dis + edgeWeight < dist[adjNode])
                {
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dist[adjNode], adjNode});

                    // Update parent to reconstruct path later
                    parent[adjNode] = node;
                }
            }
        }

        // Step 4: If destination node is unreachable
        if (dist[n] == 1e9)
            return {-1};

        // Step 5: Reconstruct the path from node n back to node 1 using parent[]
        vector<int> path;
        int node = n;

        while (parent[node] != node)
        {
            path.push_back(node);
            node = parent[node];  // Move to parent
        }
        path.push_back(1);  // Finally, add the source node

        reverse(path.begin(), path.end());  // Reverse to get 1 → n path

        return path;
    }
};

int main()
{
    // Example input
    int V = 5, E = 6;
    vector<vector<int>> edges = {
        {1, 2, 2},
        {2, 5, 5},
        {2, 3, 4},
        {1, 4, 1},
        {4, 3, 3},
        {3, 5, 1}
    };

    Solution obj;
    vector<int> path = obj.shortestPath(V, E, edges);

    // Print the shortest path from node 1 to node n
    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i] << " ";
    }
    cout << endl;

    return 0;
}
