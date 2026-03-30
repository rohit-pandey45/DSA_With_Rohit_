class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //Approach --> flatten 2d array into 1d array
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0, high =m*n-1;       //high is pointing to the last element of the matrix assuming it to be a 1d matrix
        while(low<=high){
            int mid = (low+high)/2;
            int row = mid/m;            //convert the 2d index to id index
            int col = mid%m;        //converts 2d index to 1d index
            if(matrix[row][col] == target){
                return true;
            }
            else if (matrix[row][col]<target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }

        }
        return false;
    }
};
// class Solution {
// private:
//     bool binarySearch(vector<int>& matrix, int target){
//         int low = 0;
//         int high = matrix.size()-1;
//         while(low <= high){
//             int mid = low + ((high - low)/2);
//             if(matrix[mid] == target){
//                 return true;
//             }
//             else if(matrix[mid] < target){
//                 low = mid + 1;
//             }
//             else{
//                 high = mid - 1;
//             }
//         }
//         return false;
//     }
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         int low = 0;
//         int high = n-1;
//         // int high = (m*n) - 1;
//         while(low <= high){
//             int mid = low + ((high - low)/2);
//             for(int i = 0; i<m; i++){
//                 if(matrix[i][0] <= target && target <= matrix[i][n-1]){
//                     return binarySearch(matrix[i],target);
//                 }
//             }

//         }
//         return false;
//     }
// };