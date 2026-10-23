class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        
        vector<vector<int>> ans(n, vector<int>(m, -1));

        queue<pair<int, int>> q; //row

        // Push all 0s into the queue and mark their distance as 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        // Direction vectors for moving Up, Down, Left, Right
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        // Multi-Source BFS
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                // Check bounds and if the neighbor hasn't been visited yet
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && ans[nr][nc] == -1) {
                    ans[nr][nc] = ans[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        return ans;
    }
};