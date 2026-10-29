class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector <int> ans(nums.size(),0);

        int odd_idx=0;
        int even_idx=1;


        for(int i=0;i<nums.size();i++){
            if (nums[i]>0){
                ans[odd_idx]=nums[i];
                odd_idx+=2;
            }
            else{
                ans[even_idx]=nums[i];
                even_idx+=2;

            }

        }
        return ans;
        
    }
};