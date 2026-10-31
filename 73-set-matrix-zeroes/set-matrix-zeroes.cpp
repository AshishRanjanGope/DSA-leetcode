class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        unordered_set<int> idx_i; // contains i 
        unordered_set<int> idx_j; // contains j

        for (int i = 0; i < m; i++) {
            for (int j= 0; j < n; j++) {
                if (mat[i][j]==0){
                    idx_i.insert(i);
                    idx_j.insert(j);

                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j= 0; j < n; j++) {
                if (idx_i.find(i)!= idx_i.end()){
                    mat[i][j]=0;
                    
                }
                else if (idx_j.find(j)!= idx_j.end()){
                    mat[i][j]=0;

                }
            }}

    }
};