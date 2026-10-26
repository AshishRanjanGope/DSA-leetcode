class Solution {
public:
    using p = pair<int, int>;
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;
        p src = {0, 0};
        p dest = {n - 1, n - 1};

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        dist[0][0] = 1;

        queue<pair<int, p>> q;

        if (grid[0][0] == 0) {
            q.push({1, {0, 0}});
        }

        int dr[] = {-1, 1, 1, 0, -1, 0, 1, -1};
        int dc[] = {-1, 0, 1, 1, 0, -1, -1, 1};

        while (!q.empty()) {
            int d = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;

            q.pop();

            if (r==dest.first && c== dest.second){
                return d;
            }

            for (int i = 0; i < 8; i++) {
                int newr = r + dr[i];
                int newc = c + dc[i];

                if (newr >= 0 && newc >= 0 && newr < n && newc < n &&
                    grid[newr][newc] == 0 &&
                    d + 1 < dist[newr][newc]) { // boundary +walking + dist
                                                // storing condition
                    dist[newr][newc] = d + 1;   // increase the distance by one

                    q.push({d + 1, {newr, newc}});
                }
            }
        }
        return -1;
    }
};