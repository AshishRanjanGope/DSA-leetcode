class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        // combining two array

        int m = nums.size();

        vector<int> num1 = nums; // nums+ nums not allowed
        num1.insert(num1.end(), nums.begin(), nums.end());

        int n = num1.size();
        vector<int> ans(m, -1);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            // pop
            while (!st.empty() && st.top() <= num1[i]) {
                st.pop();
            }

            // update arr
            if (!st.empty() && i < m) {
                ans[i] = st.top();
            }

            // push
            st.push(num1[i]);
        }

        return ans;
    }
};