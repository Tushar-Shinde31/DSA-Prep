class Solution {
public:
    int solve(vector<int>& wt, vector<int>& val, int ind, int capacity, vector<vector<int>>& dp) {
        // Base case
        if (ind == 0) {
            if (wt[0] <= capacity) return val[0];
            return 0;
        }


        if (dp[ind][capacity] != -1)
            return dp[ind][capacity];


        int include = 0;
        if (wt[ind] <= capacity) {
            include = val[ind] + solve(wt, val, ind - 1, capacity - wt[ind], dp);
        }


        int exclude = 0 + solve(wt, val, ind - 1, capacity, dp);


        dp[ind][capacity] = max(include, exclude);
        return dp[ind][capacity];
    }


    int knapsack01(vector<int>& wt, vector<int>& val, int n, int W) {
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        return solve(wt, val, n - 1, W, dp);
    }
};



