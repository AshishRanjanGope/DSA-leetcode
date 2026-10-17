class Solution {
public:
    int digitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        unordered_map<int, int> mp; // num, idx
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = i;
        }

        vector<int> nums_sorted(nums.begin(), nums.end());

        auto lambda = [&](int a, int b) {
            int sum1 = digitSum(a);
            int sum2 = digitSum(b);
            if (sum1 != sum2) {
                return sum1 < sum2;
            }
            return a < b;
        };

        sort(nums_sorted.begin(), nums_sorted.end(), lambda);
        int swap_cnt = 0;

        for (int i = 0; i < nums.size(); i++) {

            int expected_val = nums_sorted[i];
            int curr_val = nums[i];

            if (expected_val == curr_val)
                continue;

            // idx
            int idx = mp[expected_val];
            // swapping
            nums[i] = expected_val;
            nums[idx] = curr_val;

            // updated mp
            mp[expected_val] = i; // expected_val moved to index i
            mp[curr_val] = idx;   // curr_val moved to index idx

            swap_cnt++;
        }
        return swap_cnt;
    }
};