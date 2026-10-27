class Solution {
public:
    bool dfsCheck(int node, vector<vector<int>>& graph, vector<int>& vis) {
        vis[node] = 1; // Mark as visiting (part of current recursion stack)

        for (auto neighbor : graph[node]) {
            // If neighbor is unvisited, run DFS on it
            if (vis[neighbor] == 0) {
                if (dfsCheck(neighbor, graph, vis)) {
                    return true; // Cycle found
                }
            } 
            // If neighbor is currently in recursion stack, cycle detected
            else if (vis[neighbor] == 1) {
                return true;
            }
        }

        // Mark node as safe (fully processed and no cycle detected)
        vis[node] = 2; 
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> vis(V, 0);

        // Run DFS directly on node i
        for (int i = 0; i < V; i++) {
            if (!vis[i] ) {
                dfsCheck(i, graph, vis);
            }
        }

        vector<int> ans;
        for (int i = 0; i < V; i++) {
            // Nodes marked as 2 are safe
            if (vis[i] == 2) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};