// Question:
// 📌 Problem: Find the First K Missing Positive Numbers

// You are given an unsorted integer array nums and an integer k.
// Your task is to return the first k positive integers that are missing from the array.

// Example 1

// Input:

// nums = [3, -1, 4, 5, 5]
// k = 3


// Output:

// [1, 2, 6]


// Explanation:

// Numbers present in nums: 3, 4, 5

// First missing positives: 1, 2, 6

// Example 2

// Input:

// nums = [2, 3, 4]
// k = 3


// Output:

// [1, 5, 6]


// Explanation:

// Numbers present: 2, 3, 4

// Missing positives: 1, then after 4 → 5, 6

// Example 3

// Input:

// nums = [-2, -3, 4]
// k = 2


// Output:

// [1, 2]


// Explanation:

// Numbers present: 4

// First missing positives: 1, 2

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


