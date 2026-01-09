class Solution {
public:
    int f(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp){
        if(j<0 || j>=mat[0].size()) return 1e8;
        if(i == 0)  return mat[0][j];
        if(dp[i][j] != -1)  return dp[i][j];
        int s = mat[i][j] + f(i-1,j,mat,dp);
        int rd = mat[i][j] + f(i-1,j-1,mat,dp);
        int ld = mat[i][j] + f(i-1,j+1,mat,dp);
        return dp[i][j] = min(s,min(rd,ld));
    }
    int minFallingPathSum(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dp(m, vector<int> (n,-1));
        for(int j = 0; j<n; j++){
            dp[0][j] = mat[0][j];
        }
        for(int i = 1; i<m; i++){
            for(int j = 0; j<n; j++){
                int s = mat[i][j] + dp[i-1][j];
                int rd = mat[i][j];
                if(j-1 >= 0){
                    rd +=  dp[i-1][j-1];
                }
                else{
                    rd += 1e8;
                }
                int ld = mat[i][j];
                if(j+1 < n){
                    ld +=  dp[i-1][j+1];
                }
                else{
                    ld += 1e8;
                }
                dp[i][j] = min(s,min(ld,rd));
            }
        }
        int maxi = 1e8;    //for maximum
        for(int i = 0; i<n; i++){
            maxi = min(maxi, dp[m-1][i]);
        }
        return maxi;
    }
};