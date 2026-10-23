class Solution {
public:
    bool DFS(vector<vector<int>>& adj, int u, vector<int> &vis) {

        if (vis[u]==1) return true;
        if (vis[u]==2) return false;
        vis[u] = 1;

        for (auto& ch : adj[u]) {
            if (DFS(adj, ch, vis)) return true;
        }

        vis[u]=2;// fully processed
        return false;
    }
    bool canFinish(int numC, vector<vector<int>>& pre) {

        vector<vector<int>> adj(numC);

        int n = pre.size();

        // creating adj list
        for (auto& p : pre) {
            adj[p[1]].push_back(p[0]);
        }

        vector<int> vis(numC, 0);

        for (int i = 0; i < numC; i++) {

            if (vis[i] == 0) {
                if (DFS(adj, i, vis))
                    return false;
            }
        }
        return true;
    }
};