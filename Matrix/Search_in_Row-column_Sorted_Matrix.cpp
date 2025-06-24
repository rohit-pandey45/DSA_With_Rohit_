// User function template for C++
class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        // your code here
        int m = mat.size();
        int n = mat[0].size();
        for (int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if (mat[i][j] == x){
                    return true;
                }
            }
        }
        return false;
    }
};