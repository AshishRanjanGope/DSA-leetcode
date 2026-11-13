class Solution {
public:
    typedef long long ll;
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<ll> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + nums[i];
        }
        int ans = n + 1;

        deque<int> dq;

        for (int i = 0; i <= n; i++) {
            while (!dq.empty() && pref[i] - pref[dq.front()] >= k) {
                ans = min(ans, i - dq.front());
                dq.pop_front();
            }
            while (!dq.empty() && pref[i] <= pref[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return ans == n + 1 ? -1 : ans;
    }
};