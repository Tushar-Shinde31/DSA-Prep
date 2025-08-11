#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int upperBound(vector<int> &arr, int x, int n) {
        int low = 0, high = n; // high = n (not n-1) to handle all elements <= x
        while (low < high) {
            int mid = (low + high) / 2;
            if (arr[mid] <= x)
                low = mid + 1;
            else
                high = mid;
        }
        return low; // number of elements <= x
    }

    int countSmallEqual(vector<vector<int>> &matrix, int m, int n, int x) {
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            cnt += upperBound(matrix[i], x, n);
        }
        return cnt;
    }

    int findMedian(vector<vector<int>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int low = INT_MAX, high = INT_MIN;
        for (int i = 0; i < m; i++) {
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][n - 1]);
        }

        int desired = (m * n + 1) / 2;

        while (low < high) {
            int mid = low + (high - low) / 2;
            int cnt = countSmallEqual(matrix, m, n, mid);

            if (cnt < desired)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix1 = {{1, 4, 9}, {2, 5, 6}, {3, 7, 8}};
    cout << sol.findMedian(matrix1) << endl; // Output: 5

    vector<vector<int>> matrix2 = {{1, 3, 8}, {2, 3, 4}, {1, 2, 5}};
    cout << sol.findMedian(matrix2) << endl; // Output: 3
}
