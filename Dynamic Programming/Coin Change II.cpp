class Solution {
public:
    // int f(int ind, int t, vector<int> &coins, vector<vector<int>> &dp){
    //     if(ind == 0){
    //         return (t%coins[0] == 0);
    //     }
    //     if(dp[ind][t] != -1)    return dp[ind][t];
    //     int notTake = 0 + f(ind-1, t, coins, dp);
    //     int take = 0;
    //     if(coins[ind] <= t){
    //         take += f(ind,t - coins[ind],coins,dp);
    //     }
    //     return take+notTake;
    // }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        vector<vector<int>> dp(n, vector<int> (amount+1, 0));
        for(int t = 0; t<=amount; t++){
            dp[0][t] = (t%coins[0] == 0);
        }
        for(int ind = 1; ind<n; ind++){
            for(int target = 0; target<= amount; target++){
                long long notTake = dp[ind-1][target];
                long long take = 0;
                if(coins[ind] <= target){
                    take = dp[ind][target - coins[ind]];
                }
                dp[ind][target] = take + notTake;
            }
        }
        return dp[n-1][amount];
    }
};