class Solution {
public:
    void DFS(vector<vector<int>>& image, int sr, int sc, int color, int st) {
        int m = image.size();
        int n = image[0].size();

        if (sc < 0 || sr < 0 || sc >= n || sr >= m) {
            return;
        }

        if (image[sr][sc] == st) {

            image[sr][sc] = color;
            DFS(image, sr, sc + 1, color, st); // right
            DFS(image, sr, sc - 1, color, st); // left
            DFS(image, sr + 1, sc, color, st); // top
            DFS(image, sr - 1, sc, color, st); // down
        }
        return;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {

                                    
        int m = image.size();
        int n = image[0].size();
        int st = image[sr][sc];
        if (st==color){
            return image;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                DFS(image, sr, sc, color, st);
            }
        }

        return image;
    }
};