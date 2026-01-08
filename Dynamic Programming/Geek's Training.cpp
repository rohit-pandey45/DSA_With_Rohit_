class Solution {
  public:
    int f(int days, int last, vector<vector<int>>& arr, vector<vector<int>>& dp){
        //BASE CASE
        if(days == 0){
            int maxi = 0;
            for(int i = 0; i<3; i++){
                if(i != last){
                    maxi = max(maxi, arr[0][i]);
                }
            }
            return maxi;
        }
        //Main LOGIC
        if(dp[days][last] != -1)    return dp[days][last];
        int maxi = 0;
        for(int i = 0; i<3; i++){
            if(i != last){
                int points = arr[days][task] + f(days-1, task, arr, dp);
                maxi = max(maxi,points);
            }
        }
        return dp[days][last] = maxi;
    }
    int maximumPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int> (4,-1));
        return f(n-1, 3, arr, dp);
        
    }
};