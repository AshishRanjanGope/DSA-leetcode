class Solution {
private:
    void DFS(vector<vector<int>> AdjLs, int idx, vector<int>& visited) {
        visited[idx] = 1;
        for (auto& it : AdjLs[idx]) {
            if (!visited[it]) {

                DFS(AdjLs, it, visited);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<vector<int>> AdjLs(V);
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < isConnected[0].size(); j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    AdjLs[i].push_back(j);
                    AdjLs[j].push_back(j);
                }
            }
        }

        int v1 = AdjLs.size();
        vector<int> visited(v1, 0);
        int cnt = 0;

        for (int i = 0; i < v1; i++) {

            if (!visited[i]) {
                cnt++;
                DFS(AdjLs, i, visited);
            }
        }
        return cnt;
    }
};