

class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        //flatten 2d array in to 1d
        int n = mat.size();
        int m = mat[0].size();
        int low = 0;        //pointiong to 0th index posn of supposed 1d array
        int high = m*n-1;       //pointing to last  index position of considered 1d array
        while(low<=high){
            int mid = (low+high)/2;
            int row = mid/m;
            int col = mid%m;
            if(mat[row][col] == x){
                return true;
            }
            else if (mat[row][col] < x){
                low = mid+1;
            }
            else{
                high = mid - 1;
            }
        }
        return false;
    }
};