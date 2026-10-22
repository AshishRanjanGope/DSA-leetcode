typedef pair<int, int> P;
class Solution {

public:
    int primAlgo(vector<vector<P>>& adj, int V) {

        priority_queue<P, vector<P>, greater<P>> pq;

        pq.push({0, 0}); // wt, node

        vector<bool> inMST(V, false);

        int sum = 0;

        while (!pq.empty()) {
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (inMST[node]) {
                continue;
            }
            sum+=wt;

            inMST[node] = true;

            for (auto& tmp : adj[node]) {
                int n = tmp.first;
                int dis = tmp.second;

                if (inMST[n])
                    continue;

                
                pq.push({dis, n});
            }
        }
        return sum;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {

        // creating adj list
        int V = points.size();

        vector<vector<P>> adj(V);

        for (int i = 0; i < V; i++) {
            for (int j = i + 1; j < V; j++) {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dis = abs(x1 - x2) + abs(y1 - y2);

                adj[i].push_back({j, dis});
                adj[j].push_back({i, dis});
            }
        }
        return primAlgo(adj, V);
    }
};