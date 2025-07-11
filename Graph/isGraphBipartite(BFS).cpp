class Solution {
private:
    bool check(int node, int V, vector<vector<int>>& adj, int color[]) {
        for (auto it : adj[node]) {
            if (color[it] == -1) {
                color[it] = !color[node];
                if (!check(it, V, adj, color)) {
                    return false;
                }
            } else if (color[it] == color[node]) {
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& adj) {
        int V = adj.size();
        int color[V];
        for (int i = 0; i < V; i++) {
            color[i] = -1;
        }

        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                color[i] = 0;
                if (!check(i, V, adj, color)) {
                    return false;
                }
            }
        }
        return true;
    }
};
