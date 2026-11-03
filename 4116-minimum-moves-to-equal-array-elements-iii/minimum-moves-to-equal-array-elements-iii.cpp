class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max_ele= *max_element(begin(nums), end(nums));
        long long sum=0;

        for (int i=0 ; i< nums.size();i++){
            sum+=max_ele- nums[i];
        }
        return sum;
        
    }
};