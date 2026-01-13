class Solution {
public:
    // int f(int ind, vector<int>& coins, int amount, vector<vector<int>> &dp){
    //     int n = coins.size();
    //     //Base Case
    //     if(amount == 0) return 0;
    //     if (ind == 0) {
    //         if (amount % coins[0] == 0)
    //             return amount / coins[0];
    //         else
    //             return 1e9;
    //     }
    //     if(dp[ind][amount] != -1) return dp[ind][amount]; 
    //     //Main Logic
    //     int notTake = 0 + f(ind-1,coins,amount,dp);
    //     int take = 1e9;
    //     if(coins[ind] <= amount){
    //         take = 1 + f(ind,coins,amount - coins[ind],dp);
    //     }
    //     return dp[ind][amount] = min(take,notTake);
    // }
    int coinChange(vector<int>& coins, int amount) {
        // int n = coins.size();
        // vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        // int ans =  f(n-1,coins,amount,dp);
        // if(ans >= 1e9){
        //     return -1;
        // }
        // return ans;
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, 0));
        for(int i = 0; i<=amount; i++){
            if(i % coins[0] == 0)   dp[0][i] = i/coins[0];
            else    dp[0][i] = 1e9;
        }
        for(int ind = 1; ind<n; ind++){
            for(int target = 0; target <= amount; target++){
                int notTake = 0 + dp[ind-1][target];
                int take = 1e9;
                if(coins[ind] <= target){
                    take = 1 + dp[ind][target - coins[ind]];
                }
                dp[ind][target] = min(take,notTake);
            }
        }
        int ans =  dp[n-1][amount];
        if(ans >= 1e9){
            return -1;
        }
        return ans;
    }
};