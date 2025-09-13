#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findFirstKMissing(vector<int>& nums, int k) {
        int n = nums.size();

        // Step 1: Replace invalid numbers with 1
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0 || nums[i] > n) {
                nums[i] = 1;
            }
        }

        // Step 2: Mark presence using the negative sign trick
        for (int i = 0; i < n; i++) {
            int ind = abs(nums[i]) - 1;
            if (nums[ind] > 0) {
                nums[ind] *= -1;
            }
        }

        // Step 3: Collect missing numbers inside [1..n]
        vector<int> res;
        unordered_set<int> present;
        for (int i = 0; i < n && (int)res.size() < k; i++) {
            if (nums[i] > 0) {       // positive → missing
                res.push_back(i + 1);
            } else {                 // negative → present
                present.insert(i + 1);
            }
        }

        // Step 4: If still not enough, check numbers beyond n
        int candidate = n + 1;
        while ((int)res.size() < k) {
            if (present.find(candidate) == present.end()) {
                res.push_back(candidate);
            }
            candidate++;
        }

        return res;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<int> nums = {2, 3, 4, 7, 11};
    int k = 5;
    vector<int> ans = sol.findFirstKMissing(nums, k);

    cout << "First " << k << " missing numbers: ";
    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}

