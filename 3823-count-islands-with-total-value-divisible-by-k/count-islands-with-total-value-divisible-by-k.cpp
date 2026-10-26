class Solution {
public:
    long long bfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int i,
                  int j) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q; // store sum
        vis[i][j] = 1;
        q.push({i, j});
        long long sum = grid[i][j];

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};
            for (int k = 0; k < 4; k++) {
                int r = x + dr[k];
                int c = y + dc[k];

                if (r < 0 || c < 0 || r >= n || c >= m || grid[r][c] == 0 || vis[r][c])
                    continue;
                vis[r][c] = 1;
                sum += grid[r][c];

                q.push({r,c});
            }
        }
        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] > 0) {
                    if (bfs(grid, vis, i, j) % k == 0) {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};