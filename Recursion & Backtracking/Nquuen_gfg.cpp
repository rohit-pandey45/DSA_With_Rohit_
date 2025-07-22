// User function Template for C++

class Solution {
  public:
    void solve(int col, int n, vector<int>&queens,vector<vector<int>>& ans, vector<int>& leftrow, vector<int>& upperdiag, vector<int>& lowerdiag){
        if(col == n){
            vector<int> temp = queens;
            for(int& q : temp)  q++;
            ans.push_back(temp);
            return;
        }
        for(int row = 0; row<n; row++){
            if(leftrow[row] == 0 && lowerdiag[row + col] == 0 && upperdiag[n - 1 + col - row] == 0){
                queens[col] = row;
                leftrow[row] = lowerdiag[row+col] = upperdiag[n - 1 + col - row] = 1;
                
                solve(col + 1, n, queens, ans, leftrow, upperdiag, lowerdiag);
                //Backtrack
                leftrow[row] = lowerdiag[row+col] = upperdiag[n - 1 + col - row] = 0;
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> ans;
        vector<int> queens(n,0);
        vector<int> leftrow(n,0);
        vector<int> upperdiag(2*n - 1,0);
        vector<int> lowerdiag(2*n - 1,0);
        solve(0,n, queens,ans,leftrow,upperdiag,lowerdiag);
        return ans;
        
    }
};