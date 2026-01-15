class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1,0));
        for(int j = 0; j<n2; j++)   dp[0][j] = 0;
        for(int i = 0; i<n1; i++)   dp[i][0] = 0;
        for(int ind1 = 1; ind1<=n1; ind1++){
            for(int ind2 = 1; ind2<=n2; ind2++){
                if(text1[ind1-1] == text2[ind2-1]){
                    dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
                }
                //If No Match
                else{
                    dp[ind1][ind2] = max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
                }
            }
        }
        return dp[n1][n2];
        // return f(n1-1,n2-1,text1, text2,dp);
        // return f(n1,n2,text1, text2,dp);
    }
    int minDistance(string word1, string word2) {
        return word1.size() + word2.size() - 2*longestCommonSubsequence(word1,word2);
    }
};