class Solution {
public:
    bool solve(int ind, vector<int>& nums, int n, int target, vector<vector<int>>& dp) {
        if (target == 0) return true;
        if (ind >= n || target < 0) return false;

        if (dp[ind][target] != -1)
            return dp[ind][target];

        bool incl = solve(ind + 1, nums, n, target - nums[ind], dp);
        bool excl = solve(ind + 1, nums, n, target, dp);

        return dp[ind][target] = incl || excl;
    }

    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (int i = 0; i < nums.size(); i++) {
            total += nums[i];
        }

        if (total % 2 != 0)
            return false;

        int target = total / 2;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return solve(0, nums, n, target, dp);
    }
};
