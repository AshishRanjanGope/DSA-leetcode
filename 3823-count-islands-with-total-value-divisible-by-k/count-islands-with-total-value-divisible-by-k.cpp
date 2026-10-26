class Solution {
public:

long long dfs(vector<vector<int>>& grid,vector <vector <int> > &vis,int i, int j ){
       int n= grid.size();
        int m= grid[0].size();
         if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0 || vis[i][j]) return 0;
        
    
   
        vis[i][j]=1;
        
   return grid[i][j]
             + dfs(grid, vis, i + 1, j) + dfs(grid, vis, i - 1, j)
             + dfs(grid, vis, i, j + 1) + dfs(grid, vis, i, j - 1);




 
}

    int countIslands(vector<vector<int>>& grid, int k) {
        int n= grid.size();
        int m= grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m,0));
        int cnt=0;

        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (!vis[i][j] && grid [i][j]>0){
                    if (dfs(grid,vis,i,j)%k==0){
                        cnt++;
                    }
                }
            }
        }
        return cnt;

        
    }
};