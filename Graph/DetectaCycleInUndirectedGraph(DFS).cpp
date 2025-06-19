class Solution {
private:
    bool dfs(int node, int parent, vector<int>& vis, vector<int> adj[]) {
        vis[node] = 1;
        for (auto adjacentNode : adj[node]) {
            if (!vis[adjacentNode]) {
                if (dfs(adjacentNode, node, vis, adj) == true)
                    return true;
            } else if (adjacentNode != parent) {
                return true;
            }
        }
        return false;
    }

public:
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V, 0); // ✅ Correctly initialized visited array
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, -1, vis, adj) == true)
                    return true;
            }
        }
        return false; // ✅ This line was incorrectly placed outside the function
    }
};
