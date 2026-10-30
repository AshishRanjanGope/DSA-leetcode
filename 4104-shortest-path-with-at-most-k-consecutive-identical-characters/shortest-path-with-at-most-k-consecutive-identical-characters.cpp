class Solution {
public:
    typedef pair<int, int> p;
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        // result[node][count] = min cost to reach node with 'count' consecutive
        // identical chars
        vector<vector<int>> result(n, vector<int>(k + 1, INT_MAX));

        priority_queue<pair<int, p>, vector<pair<int, p>>,
                       greater<pair<int, p>>>
            pq;

        result[0][1] = 0;
        pq.push({0, {0, 1}});

        while (!pq.empty()) {

            int d = pq.top().first;
            int node = pq.top().second.first;
            int count = pq.top().second.second;
            pq.pop();

            if (d > result[node][count])
                continue;

            if (node == n - 1)
                return d;

            for (auto& vec : adj[node]) {
                int adjNode = vec.first;
                int wt = vec.second;

                int newCount =
                    (labels[adjNode] == labels[node]) ? count + 1 : 1;

                if (newCount > k)
                    continue;

                int newDist = d + wt;
                if (newDist < result[adjNode][newCount]) {
                    result[adjNode][newCount] = newDist;
                    pq.push({newDist, {adjNode, newCount}});
                }
            }
        }

        return -1;
    }
};