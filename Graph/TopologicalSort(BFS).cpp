class Solution {
public:
    vector<int> topoSort(int V, vector<int> adj[]) {
        int indegree[V] = {0};
        
        // Calculate indegree of each node
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> topo; 
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            //node is in your topo topoSort
            //so please remove it from indegree
 
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }

        return topo;
    }
};
