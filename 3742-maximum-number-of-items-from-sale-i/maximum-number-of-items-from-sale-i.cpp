class Solution {
public:
    int solve (int n, int budget, vector<vector<int>>& items, vector <int> &copies,vector <vector<int>> &dp){
        int cheapest = items[0][1];
        if (n==0){return budget/cheapest;}
        if(dp[n][budget]!=-1){
            return dp[n][budget];
        }
        int take =0;
        int skip=0;

        if (items[n-1][1]<=budget){
           take = 1+ copies[n-1]+ solve (n-1, budget-items[n-1][1], items, copies,dp);

        }
        skip= solve(n-1,budget, items,copies,dp);

        return dp[n][budget]=max(take, skip);
    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {


        int n = items.size();
        vector<vector<int>> dp(n+1,vector<int>(budget+1,-1));
       sort (items.begin(),items.end(), [](vector <int> &a , vector<int>&b){
        return a[1]<b[1];
       });
        //copies vector //n2
        vector <int> copies(n+1,0);
        for(int i=0;i<n;i++){
            int faci= items[i][0];
            for(int j=0;j<n;j++){
                if (i==j){
                    continue;
                }
            int facj= items[j][0];
                if (facj%faci==0){
                    copies[i]++;

                }

            }
        }

    

       return solve (n,budget, items, copies,dp);

       

        
    }
};