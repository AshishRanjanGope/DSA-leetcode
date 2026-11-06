class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
      
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

  
        int q_size = queries.size();
        vector<pair<int, int>> sorted_queries(q_size);
        for (int i = 0; i < q_size; ++i) {
            sorted_queries[i] = {queries[i], i};
        }
        sort(sorted_queries.begin(), sorted_queries.end());

        vector<int> ans(q_size);
        vector<int> counts(n + 1, 0); 
        int active_servers = 0;
        int left = 0, right = 0;
        int m = logs.size();

        for (auto& q : sorted_queries) {
            int q_time = q.first;
            int q_idx = q.second;
            int start_time = q_time - x;

     
            while (right < m && logs[right][1] <= q_time) {
                if (counts[logs[right][0]]++ == 0) {
                    active_servers++;
                }
                right++;
            }

            while (left < m && logs[left][1] < start_time) {
                if (--counts[logs[left][0]] == 0) {
                    active_servers--;
                }
                left++;
            }

            ans[q_idx] = n - active_servers;
        }

        return ans;
    }
};