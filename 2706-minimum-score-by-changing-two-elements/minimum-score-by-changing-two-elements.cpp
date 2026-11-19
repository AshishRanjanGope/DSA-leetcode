class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n= nums.size();
        if (n==3){
            return 0;
        }
        sort (nums.begin(), nums.end());
        
        //case 1
        int ans1= nums[n-2]-nums[1];
        // case2
        int ans2 = nums[n-1]-nums[2];
        //case3
        int ans3 = nums[n-3]-nums[0];

        return min({ans1, ans2, ans3});
       
        
        
    }
};