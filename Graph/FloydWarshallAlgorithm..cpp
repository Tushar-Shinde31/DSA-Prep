class Solution {
public:
    void shortestDistance(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Step 1: Replace -1 with a large number to represent infinity
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == -1)
                    matrix[i][j] = 1e9;

                if (i == j)
                    matrix[i][j] = 0;  
            }
        }

        // Step 2: Floyd-Warshall algorithm core logic
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (matrix[i][k] != 1e9 && matrix[k][j] != 1e9)
                        matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }

        // Step 3: Replace 'infinity' with -1 again for unreachable nodes
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1e9)
                    matrix[i][j] = -1;
            }
        }
    }
};
