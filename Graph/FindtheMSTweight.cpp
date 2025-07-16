class Solution {
public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // Min-heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> vis(V, 0);  // Visited array
        pq.push({0, 0});        // Start from node 0 with weight 0

        int sum = 0;            // Total weight of MST

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int wt = it.first;
            int node = it.second;

            if (vis[node]) continue;

            vis[node] = 1;
            sum += wt;

            for (auto edge : adj[node]) {
                int adjNode = edge[0];
                int edW = edge[1];

                if (!vis[adjNode]) {
                    pq.push({edW, adjNode});
                }
            }
        }

        return sum;
    }
};
