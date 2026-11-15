class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        // combining two array

        // int m = nums.size();

        // vector<int> num1 = nums; // nums+ nums not allowed
        // num1.insert(num1.end(), nums.begin(), nums.end());

        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for (int i = 2*n - 1; i >= 0; i--) { // space optimal
            int curr= nums[i%n];
            // pop
            while (!st.empty() && st.top() <= curr) {
                st.pop();
            }

            // update arr
            if (!st.empty() && i < n) {
                ans[i] = st.top();
            }

            // push
            st.push(curr);
        }

        return ans;
    }
};