class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n= nums.size();

        int max_so_far=nums[0];
      

        int prev_max= max_so_far;
        int prev_min= max_so_far;

        for (int i=1;i<n;i++){

            int temp1= nums[i]* prev_max;
            int temp2 = nums[i]* prev_min;



           prev_max = max({nums[i],temp1, temp2});
           prev_min = min({nums[i],temp1, temp2});



            max_so_far = max(max_so_far, prev_max);
           
            



            



        }
        return max_so_far;
        
    }
};