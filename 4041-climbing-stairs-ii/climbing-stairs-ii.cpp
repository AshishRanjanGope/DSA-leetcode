class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
       
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0; 
        for (int i = 1; i <= n; ++i) {
          
            for (int jump = 1; jump <= 3; ++jump) {
                if (i - jump >= 0) {
                  
                    int current_cost = dp[i - jump] + costs[i - 1] + (jump * jump);
                    dp[i] = min(dp[i], current_cost);
                }
            }
        }

        return dp[n];
    }
};