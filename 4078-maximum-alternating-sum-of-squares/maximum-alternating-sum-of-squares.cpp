class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {

       for (int i=0;i<nums.size();i++){
            nums[i]=abs(nums[i]);
       }
       sort(nums.begin(),nums.end());

       long long neg_sum=0;
       long long pos_sum=0;

       for (int i =0;i<nums.size()/2;i++){
                neg_sum+=nums[i]*nums[i];

       }
       for (int i =nums.size()/2;i<nums.size();i++){
                pos_sum+=nums[i]*nums[i];

       }

       return pos_sum-neg_sum;
       
  

        
    }
};