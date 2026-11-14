class Solution {
public:
    int minSubArrayLen(int k, vector<int>& nums) {
        int n= nums.size();
        int l= 0;
        int r=0;
        int min_len= n+1;
        int sum = 0;

        while (r<n){
            sum+=nums[r];
            while (sum>=k){
                min_len = min(min_len,r-l+1);
                sum -= nums[l];
                l++;
            }
            r++;

        }

        return min_len ==n+1? 0: min_len;


        
        
    }
};