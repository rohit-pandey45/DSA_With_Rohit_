
class Solution {
  public:
    // Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int>>& mat) {
        int n = mat.size();
        //First we take the transpose of the matrix
        for (int i = 0; i<n; i++){
            for (int j = i+1; j<n; j++){
                swap(mat[i][j],mat[j][i]);
            }
        }
        //we have to rotate the matrix anticlockwise
        int ind = n-1;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n/2; j++){
                int temp = mat[j][i];
                mat[j][i] = mat[ind][i];
                mat[ind][i] = temp;
                ind--;
            }
            ind = n-1;
        }
        
    }
};
