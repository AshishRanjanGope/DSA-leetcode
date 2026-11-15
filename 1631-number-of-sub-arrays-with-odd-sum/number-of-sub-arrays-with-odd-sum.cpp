class Solution {
public:
    const int MOD= 1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n= arr.size();

        int even = 1; // pref [0]=0
        int odd = 0;

    
        long long pref= 0;// space optimisation
      

        long long ans = 0;


        for (int i = 0; i < n; i++) {
            pref+=arr[i];

            if (pref % 2 == 0) {
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