class Solution {
public:
    bool DFS(vector<vector<int>>& graph, int u, vector<int>& color,
             int curr_color) {
        color[u] = curr_color;

        for (auto& v : graph[u]) {
            if (color[v] == curr_color) {
                return false;
            }
            if (color[v] == -1) {
                color[v] = 1 - curr_color;
                if (!DFS(graph, v, color, color[v])) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(
            V,
            -1); // act as color and visited vec// toggle color (0,1)
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (!DFS(graph, i, color, 1)) {
                    return false;
                }
            }
        }
        return true;
    }
};