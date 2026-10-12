class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int mod=1e9+7;
        vector<int> freq(30, 0);
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<30;j++){
                if(nums[i]& (1<<j)){
                    freq[j]++;
                }
            }
        }
        int ans=0;
        for(int i=0;i<k;i++){
            int x=0;

             for(int j=0;j<30;j++){
                if (freq[j]){
                    x=(x%mod+(1LL<<j)%mod)%mod;
                    freq[j]--;

                }
             }
             x=x%mod;
             ans=(ans%mod+(1LL*x*x)%mod)%mod;
        }
        return ans%mod;
    }
};