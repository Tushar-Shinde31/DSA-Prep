class Solution {
private:
    bool checkCycle(int node, vector<int> adj[], int vis[], int dfsVis[]) {
        vis[node] = 1;
        dfsVis[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (checkCycle(it, adj, vis, dfsVis))
                    return true;
            } else if (dfsVis[it]) {
                return true;
            }
        }

        dfsVis[node] = 0;  // ✅ Fix: should reset current node, not 'it'
        return false;
    }

public:
    bool isCycle(int N, vector<int> adj[]) {
        int vis[N], dfsVis[N];
        memset(vis, 0, sizeof(vis));
        memset(dfsVis, 0, sizeof(dfsVis));

        for (int i = 0; i < N; i++) {
            if (!vis[i]) {
                if (checkCycle(i, adj, vis, dfsVis)) {  // ✅ Fix: call correct function
                    return true;
                }
            }
        }

        return false;
    }
};
