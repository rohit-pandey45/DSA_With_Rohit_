class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        int n = mat.size();     //no of rows
        int m = mat[0].size();      //no of columns
        int left = 0;       //poitnting to 1
        int top = 0;        //poitnting to 1
        int right = m-1;        //poitnting to 4, value = 3
        int bottom = n-1;       //poitnting to 13, value = 3
        vector<int> ans;
        while(top<=bottom && left<=right){
            for (int i = left; i<=right; i++){
                ans.push_back(mat[top][i]);      //1,2,3,4 gets pushed to ans, again 6,7 gets pushed
            }
            top++;      //top  = 1 , 
            for (int i = top; i<=bottom; i++){
                ans.push_back(mat[i][right]);       //8,12,16 gets pushed to ans, 11 gets pushed
            }
            right--;        //right = 2
            if(top<=bottom){
                for (int i = right; i >= left; i--){
                    ans.push_back(mat[bottom][i]);      //15,14,13 gets pushed, 10 gets pushed
                }
                bottom--;       //bottom = 2
            }
            if(left<=right){
                for (int i = bottom; i>=top; i--){
                    ans.push_back(mat[i][left]);        //9,5 gets pushed
                }
                left++;
            }
        }
        return ans;
    }
};