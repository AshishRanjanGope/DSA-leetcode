class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue < pair<pair<int, int>, int> >q; // row, col and time
        vector<vector<int>> vis(m,vector<int>(n,0));
        int cnt_fresh= 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                  
                }
                if (grid[i][j]==1)cnt_fresh++;
               
            }
        }

        int tm = 0;
        int cnt=0;

        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();

            tm = max(tm, t);

            // del_rows -> change in rows

            int drow[] = {-1, 0, 1, 0};
            int dcol[] = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++) {
                int row = r + drow[i];
                int col = c + dcol[i];

                // boundary condition
                if (row >= 0 && col >= 0 && row < m && col < n &&
                    vis[row][col] == 0 && grid[row][col] == 1) {
                    q.push({{row, col}, t + 1});
                    vis[row][col] = 2;// nu
                    cnt++;
                }
            }
        }
        if (cnt!= cnt_fresh) return -1;


       
        return tm;
    }
};