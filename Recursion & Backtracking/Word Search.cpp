class Solution {
  public:
    bool solve(vector<vector<char>>& mat, string& word,int i, int j, int ind, vector<vector<bool>>&vis){
    //base case
        if(ind == word.length())    return true;
        
        if(i<0 || j<0 || i>=mat.size() || j>=mat[0].size() || vis[i][j] == true || mat[i][j] != word[ind])    return false;
    //recursive case
        vis[i][j] = true;
        //Check for the next letter of the word towards right,left,top and bottom of the current index
        if(solve(mat,word,i+1,j,ind+1,vis) || solve(mat,word,i-1,j,ind+1,vis)
        || solve(mat,word,i,j+1,ind+1,vis) || solve(mat,word,i,j-1,ind+1,vis))  return true;
        vis[i][j] = false;  //Backtrack if none of the conditions is true
        
        return false;
        
    }
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(mat[i][j] == word[0]){
                    if(solve(mat,word,i,j,0,vis)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};