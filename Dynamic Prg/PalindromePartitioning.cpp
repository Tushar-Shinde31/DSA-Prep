class Solution {
public:
    bool isPalindrome(int start, int end, const string &s){
        while(start < end){
            if(s[start] != s[end]) 
                return false;
            start++;
            end--;
        }
        return true;
    }

    int solve(int i, int n, const string &s, vector<int> &dp){
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];

        int minCost = INT_MAX;

        for(int j = i; j < n; j++){
            if(isPalindrome(i, j, s)){
                int cost = 1 + solve(j + 1, n, s, dp);
                minCost = min(minCost, cost);
            }
        }
        return dp[i] = minCost;
    }

    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return solve(0, n, s, dp) - 1;  
    }
};
