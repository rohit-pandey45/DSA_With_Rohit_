class Solution {
public:
    bool issafe(vector<string>& board, int row, int col,int n){
        //Horizontal
        for(int j = 0; j<n; j++){
            if(board[row][j] == 'Q'){
                return false;
            }
        }
        //Vertical
        for(int i = 0; i<n; i++){
            if(board[i][col] =='Q'){
                return false;
            }
        }
        //Upper Left Diagonal
        for(int i = row, j = col; i>=0 && j>=0; i--, j--){
            if(board[i][j] =='Q'){
                return false;
            }
        }
        //Upper Right Diagonal
        for(int i = row-1, j = col+1; i>=0 && j<n; i--, j++){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }
    void NQueens(vector<string>& board, int row, int n, vector<vector<string>>& ans){
        //Base Case
        if(row == n){
            ans.push_back({board});
            return;
        }
        for(int j = 0; j<n; j++){
            if(issafe(board,row,j,n)){
                board[row][j] = 'Q';
                NQueens(board,row+1,n,ans);
                //BackTrack
                board[row][j] = '.';
            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        vector<vector<string>> ans;
        NQueens(board,0,n,ans);
        return ans;
    }
};