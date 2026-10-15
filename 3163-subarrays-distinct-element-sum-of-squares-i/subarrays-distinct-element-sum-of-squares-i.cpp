class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();

        for (int l = 0; l < n; l++) {
            for (int r = l; r < n; r++) {
                set<int> s;

                for (int i = l; i <= r; i++) {
                    s.insert(nums[i]);
                }
                ans += (s.size()) * s.size();
            }
        }
        return ans;
    }
};