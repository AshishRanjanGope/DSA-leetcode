class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        vector<long long >ans(nums.size());
        for (int i =0;i<nums.size();i++){
            ans[i]=1LL*nums[i]*nums[i];
        }
        nth_element(begin(ans),begin(ans)+n/2,end(ans));

        long long a = accumulate(begin(ans),begin(ans)+n/2,0LL);
        long long b = accumulate(begin(ans)+n/2,end(ans),0LL);
        return b-a;
        
    }
};