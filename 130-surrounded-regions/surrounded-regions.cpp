class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j,
             vector<vector<int>>& idx) {
        int m = grid.size();
        int n = grid[0].size();

        // Boundary check
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 'X') {
            return;
        }

        // Mark  as visited
        idx.push_back({i, j});
        grid[i][j]='X';

        dfs(grid, i + 1, j, idx);
        dfs(grid, i - 1, j, idx);
        dfs(grid, i, j + 1, idx);
        dfs(grid, i, j - 1, idx);
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> idx;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0 || j == n - 1 || i == m - 1 &&
                    board[i][j] == 'O') {
                    dfs(board, i, j, idx);
                }
            }
        }
        vector<vector<char>> ans(m, vector<char>(n, 'X'));
        for (int i = 0; i < idx.size(); i++) {
            int x = idx[i][0];
            int y = idx[i][1];

            ans[x][y] = 'O';
        }

        board = ans;
    }
};