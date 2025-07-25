#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int> &nums, int k) {
        unordered_map<int, int> prefixMap;  // prefixSum -> firstIndex
        int sum = 0;
        int maxLength = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            if (sum == k) {
                maxLength = i + 1;
            }

            if (prefixMap.find(sum - k) != prefixMap.end()) {
                maxLength = max(maxLength, i - prefixMap[sum - k]);
            }

            // Only store the first occurrence
            if (prefixMap.find(sum) == prefixMap.end()) {
                prefixMap[sum] = i;
            }
        }

        return maxLength;
    }
};
