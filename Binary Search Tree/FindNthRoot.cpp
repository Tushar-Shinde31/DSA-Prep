class Solution {
public:
    double multiply(double number, int n) {
        double ans = 1.0;
        for (int i = 0; i < n; i++) {
            ans = ans * number;
        }
        return ans;
    }

    double NthRoot(int n, int m) {
        double low = 0;
        double high = m;
        double eps = 1e-6;
        double mid;

        while ((high - low) > eps) {
            mid = (low + high) / 2.0;

            if (multiply(mid, n) < m) {  
                low = mid;
            } else {
                high = mid;
            }
        }
        return mid;  // returns double precision root
    }
};
