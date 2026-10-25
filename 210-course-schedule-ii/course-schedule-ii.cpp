class Solution {
public:
      bool dfs(int node, vector<vector<int>>& adj,
             vector<int>& vis, vector<int>& pathVis,
             vector<int>& topo) {

        vis[node] = 1;
        pathVis[node] = 1;

        for (int neighbor : adj[node]) {
            if (!vis[neighbor]) {
                if (dfs(neighbor, adj, vis, pathVis, topo))
                    return true;
            }
            else if (pathVis[neighbor]) {
                return true; // Cycle detected
            }
        }

        pathVis[node] = 0;
        topo.push_back(node);

        return false;
    }
    vector<int> findOrder(int numC, vector<vector<int>>& pre) {
        int V=numC;
        vector<vector<int>> adj(numC);

        for (auto& p : pre) {
            adj[p[1]].push_back(p[0]); // [1,0]    0-->1
        }
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);
        vector<int> topo;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, pathVis, topo))
                    return {};
            }
        }

        reverse(topo.begin(), topo.end());
        return topo;
    }
};