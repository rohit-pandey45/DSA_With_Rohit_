

class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchRowMatrix(vector<vector<int>> &mat, int x) {
        int n = mat.size();
        int m = mat[0].size();
        if(n == 0) return false;
        // int row = 0;
        // int col = m-1;
        for(int i = 0; i<n; i++){
            int low = 0, high = m-1;
            while(low<=high){
                int mid = (low+high)/2;
                if(mat[i][mid] == x){
                    return true;
                }
                else if (mat[i][mid]<x){
                    low = mid + 1;;
                }
                else{
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};
