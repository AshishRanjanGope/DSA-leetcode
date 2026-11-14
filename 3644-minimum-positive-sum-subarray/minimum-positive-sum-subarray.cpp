class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();

        int min_sum = INT_MAX;

        for (int x = l; x <= r; x++) {
            int sum = accumulate(nums.begin(), nums.begin() + x , 0);

            int i = 0;

            int j = x - 1;
            if (sum > 0) {
                    min_sum = min(min_sum, sum);
                }
            while (j + 1 < n) {
                sum = sum - nums[i] + nums[j + 1];
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