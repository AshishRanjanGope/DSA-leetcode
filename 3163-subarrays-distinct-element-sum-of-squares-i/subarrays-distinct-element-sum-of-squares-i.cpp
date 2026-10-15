class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();

        for (int l = 0; l < n; l++) {
            unordered_set<int> distinct_elements;
            for (int r = l; r < n; r++) {
                distinct_elements.insert(nums[r]);
                int count = distinct_elements.size();
                ans += count * count;
            }
        }

        return ans;
    }
};