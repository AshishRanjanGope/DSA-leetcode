class Solution {
public:
    bool isvalid(vector<vector<char>>& board, int i, int j, int k) {

        for (int x = 0; x < 9; x++) {
            if (k == board[x][j] - '0') {
                return false;
            }
            if (k == board[i][x] - '0') {
                return false;
            }
        }

        // boxes
        int sr;
        int sc;

        sr = (i / 3) * 3;
        sc = (j / 3) * 3;

        for (int row = sr; row < sr + 3; row++) {
            for (int col = sc; col < sc + 3; col++) {
                if (k == board[row][col] - '0') {
                    return false;
                }
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board, int i, int j) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.')
                    continue;
                else {
                    for (int k = 1; k <= 9; k++) {

                        if (isvalid(board, i, j, k)) {
                            // backtracking done
                            board[i][j] = k + '0';
                            if (solve(board, i, j)) {
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) { 
        solve(board, 0, 0); 
        }
};