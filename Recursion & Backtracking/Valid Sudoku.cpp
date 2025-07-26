class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<unordered_set<char>> rows(9), col(9), mat(9);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                char ch = board[i][j];
                //If empty element then pass
                if(ch == '.')   continue;
                //Chevk for Rows
                if(rows[i].count(ch))   return false;
                rows[i].insert(ch);
                //Check for Columns
                if(col[j].count(ch))    return false;
                col[j].insert(ch);
                //Check for Sub Matrix
                int boxind = (i/3)*3 + (j/3);
                if(mat[boxind].count(ch))   return false;
                mat[boxind].insert(ch);
            }
        }
        return true;
    }
};