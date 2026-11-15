class Solution {
public:
    const int MOD= 1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n= arr.size();

        int even = 1; // pref [0]=0
        int odd = 0;

        vector<int> pref(n + 1, 0);
        pref[0] = 0;

        long long ans = 0;

        for (int i = 1; i <= n; i++) {
            pref[i] = arr[i - 1] + pref[i - 1];
        }

        for (int i = 0; i < n; i++) {

            if (pref[i + 1] % 2 == 0) {
                if (odd) {
                    ans += odd;
                }
                even++;

            } else {
                ans += even;
                odd++;
            }
        }
        int x= ans%MOD;
        return x;
    }
};