class Solution {
public:
    // int f(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& triangle){
    //     //BASE CASE
    //     if(i == triangle.size()-1)    return triangle[i][j];
    //     //if(j == n-1)    return triangle[i][j-1]; this case will never happen as every elements diagonal is present
    //     if(dp[i][j] != -1)  return dp[i][j];

    //     int down = triangle[i][j] + f(i+1,j,dp,triangle);
    //     int diag = triangle[i][j] + f(i+1,j+1,dp,triangle);

    //     return dp[i][j] = min(down,diag);
    // }
    int minimumTotal(vector<vector<int>>& triangle) {
        // int m = triangle.size();
        // int n = triangle[0].size();
        // // vector<vector<int>> dp(m, vector<int> (n,-1));
        // vector<vector<int>> dp(m);
        // for(int i = 0; i < m; i++)
        //     dp[i].resize(triangle[i].size(), -1);
        // return f(0, 0, dp, triangle);

        // int n = triangle.size();
        // vector<vector<int>> dp = triangle;

        // for(int i = n - 2; i >= 0; i--) {
        //     for(int j = 0; j <= i; j++) {
        //         dp[i][j] += min(dp[i + 1][j], dp[i + 1][j + 1]);
        //     }
        // }
        // return dp[0][0];

        int n = triangle.size();
        vector<int> dp = triangle[n - 1];

        for(int i = n - 2; i >= 0; i--) {
            for(int j = 0; j <= i; j++) {
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
            }
        }
        return dp[0];
    }
};