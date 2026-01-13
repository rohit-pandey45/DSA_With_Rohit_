// User function Template for C++

class Solution {
  public:
    int f(int ind, int n, vector<int> &price, vector<vector<int>> &dp){
        if(ind == 0){
            return n*price[0];
        }
        if(dp[ind][n] != -1)    return dp[ind][n];
        int notTake = 0 + f(ind-1,n,price,dp);
        int take = -1e9;
        int rodlength = ind+1;
        if(rodlength <= n){
            take = price[ind] + f(ind,n - rodlength,price,dp);
        }
        return dp[ind][n] = max(take,notTake);
    }
    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<vector<int>> dp(n, vector<int> (n+1,-1));
        return f(n-1,n,price,dp);
        
    }
};