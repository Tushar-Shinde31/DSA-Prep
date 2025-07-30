int subarraysWithXorK(vector<int> a, int k) {
    int n = a.size(); 
    int cnt = 0;
    
    for (int i = 0; i < n; i++) {
        int xorr = 0;
        for (int j = i; j < n; j++) {
                xorr = xorr ^ a[j];
                if (xorr == k) 
                    cnt++;
        }
    }
    return cnt;
}
