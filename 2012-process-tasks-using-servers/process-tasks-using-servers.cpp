class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        typedef pair<int,int> p;
        typedef tuple<long long,int,int> t;
        priority_queue<p, vector<p>, greater<p>> freeS;
        priority_queue<t, vector<t>, greater<t>> busy;
        int n = servers.size(), m = tasks.size();
        for (int i = 0; i < n; i++) freeS.push({servers[i], i});

        vector<int> ans;
        long long time = 0;
        for (int i = 0; i < m; i++) {
            time = max(time, (long long)i);
            if (freeS.empty())                      // jump to earliest release
                time = max(time, get<0>(busy.top()));
            while (!busy.empty() && get<0>(busy.top()) <= time) {
                auto [tm, w, idx] = busy.top(); busy.pop();
                freeS.push({w, idx});
            }
            auto [w, idx] = freeS.top(); freeS.pop();
            ans.push_back(idx);
            busy.push({time + tasks[i], w, idx});
        }
        return ans;
    }
};