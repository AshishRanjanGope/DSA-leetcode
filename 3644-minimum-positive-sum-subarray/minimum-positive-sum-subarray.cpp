class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();

        int min_sum = INT_MAX;
        vector <int> pref(n+1,0);
        pref[0]=0;
        for(int i=1;i<=n;i++){
            pref[i]= nums[i-1]+pref[i-1];

        }

        for (int x = l; x <= r; x++) {
            

            int i = 0;

            int j = x;
            int sum = pref[j]-pref[i];
            if (sum > 0) {
                    min_sum = min(min_sum, sum);
                }
            while (j <= n) {
                sum = pref[j]-pref[i];
                if (sum > 0) {
                    min_sum = min(min_sum, sum);
                }

                i++;
                j++;
            }
        }
        return min_sum == INT_MAX ? -1 : min_sum;
    }
};