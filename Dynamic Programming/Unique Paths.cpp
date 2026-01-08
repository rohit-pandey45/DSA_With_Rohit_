class Solution {
public:
    int f(int i, int j, vector<vector<int>> &dp){
        //BASE CASE
        if(i == 0 && j == 0){
            //DESTINATION REACHED
            return 1;
        }
        //Boundary condition
        if(i < 0 || j < 0){
            return 0;
        }
        //Main Logic
        if(dp[i][j] != -1)  return dp[i][j];
        int up = f(i-1,j,dp);
        int left = f(i,j-1,dp);
        return dp[i][j] = up + left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n,-1));
        return f(m-1,n-1,dp);

    }
};