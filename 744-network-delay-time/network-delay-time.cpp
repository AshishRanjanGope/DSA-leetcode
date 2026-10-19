class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<int> min_time(n + 1, INT_MAX);
        min_time[k] = 0;
        min_time[0]=INT_MIN;

        for (int i = 1; i <= n - 1; i++) {

            for (int j = 0; j < times.size(); j++) {

                int u = times[j][0];
                int v = times[j][1];
                int t = times[j][2];

                if (min_time[u] != INT_MAX && min_time[u] + t < min_time[v]) {
                    min_time[v] = min_time[u] + t;
                }
            }
        }
        int ans = *max_element(min_time.begin(), min_time.end());

        if (ans==INT_MAX){
            return -1;
        }

        return ans;
    }
};