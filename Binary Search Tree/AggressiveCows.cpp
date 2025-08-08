class Solution {
public:
    bool canWePlace(vector<int> &nums, int dist, int cows) {
        int last = nums[0];
        int cntCows = 1; // Place first cow at first stall

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - last >= dist) {
                cntCows++;
                last = nums[i];
            }
            if (cntCows >= cows)
                return true; // We placed all cows successfully
        }
        return false;
    }

    int aggressiveCows(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        
        int low = 1; // Minimum possible distance
        int high = nums.back() - nums.front(); // Max possible distance
        int ans = 0;

        while (low <= high) {
            int mid = (low + high) / 2; // Candidate minimum distance
            if (canWePlace(nums, mid, k)) {
                ans = mid; // This distance works, try for bigger
                low = mid + 1;
            } else {
                high = mid - 1; // Too big, try smaller
            }
        }
        return ans;
    }
};
