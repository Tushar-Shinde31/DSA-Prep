#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool detectCycle(int src, vector<int> adj[], int vis[]) {
        vis[src] = 1;
        queue<pair<int, int>> q;
        q.push({src, -1});

        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;  // ✅ FIXED: q.front() instead of q.second()
            q.pop();

            for (auto adjacentNode : adj[node]) {
                if (!vis[adjacentNode]) {
                    vis[adjacentNode] = 1;
                    q.push({adjacentNode, node});
                } else if (adjacentNode != parent) { // ✅ FIXED: move inside `else`
                    return true;
                }
            }
        }
        return false;
    }

public:
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};  
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (detectCycle(i, adj, vis))  // ✅ FIXED: called `detectCycle` not `detect`
                    return true;
            }
        }
        return false;  // ✅ Moved outside loop
    }
};
