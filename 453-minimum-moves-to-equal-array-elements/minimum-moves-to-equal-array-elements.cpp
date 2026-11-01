class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min_ele= *min_element(nums.begin(),nums.end());
        long long ans=0;

        for(int i =0;i<nums.size();i++){
            ans+=nums[i]-min_ele;
        }
        return ans;
        
    }
};