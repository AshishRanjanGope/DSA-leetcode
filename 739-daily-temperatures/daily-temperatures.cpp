class Solution {
public:
    typedef pair<int, int> p;
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        stack<p> st; // idx, val
        vector<int> ans(n, 0);

        for (int i = n - 1; i >= 0; i--) { // traverse rev

            while (!st.empty() && st.top().second <= temp[i]) {
                st.pop();
            }

            if (!st.empty()) {

                ans[i] = (st.top().first - i);
            }

            st.push({i, temp[i]});
        }

        return ans;
    }
};