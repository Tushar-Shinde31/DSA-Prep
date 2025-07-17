//need to revise
class Solution {
public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // Step 1: Create a list of all edges from the adjacency list
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                int adjNode = it[0];
                int wt = it[1];
                int node = i;
                
                // To avoid duplicate edges in undirected graph, only addd if i < adjNode
                if (i < adjNode)
                    edges.push_back({wt, {node, adjNode}});
            }
        }

        // Step 2: Sort edges based on weights
        sort(edges.begin(), edges.end());

        // Step 3: Kruskal's using Disjoint Set (Union by Size + Path Compression)
        class DisjointSet {
            vector<int> parent, size;
        public:
            DisjointSet(int n) {
                parent.resize(n);
                size.resize(n, 1);
                for (int i = 0; i < n; i++)
                    parent[i] = i;
            }

            int findUPar(int node) {
                if (node == parent[node])
                    return node;
                return parent[node] = findUPar(parent[node]);
            }

            void unionBySize(int u, int v) {
                int pu = findUPar(u);
                int pv = findUPar(v);
                if (pu == pv) return;
                if (size[pu] < size[pv]) {
                    parent[pu] = pv;
                    size[pv] += size[pu];
                } else {
                    parent[pv] = pu;
                    size[pu] += size[pv];
                }
            }
        };

        DisjointSet ds(V);
        int mstWt = 0;

        for (auto edge : edges) {
            int wt = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;

            if (ds.findUPar(u) != ds.findUPar(v)) {
                mstWt += wt;
                ds.unionBySize(u, v);
            }
        }

        return mstWt; 
    }
};
