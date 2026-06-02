class Solution {
  public:
    int findMin(vector<int>& arr) {
        int low = 0;
        int res = INT_MAX;
        int n = arr.size();
        int high = n-1;
        while(low<=high){
            int mid = (low+high)/2;
            if (arr[low] <= arr[mid]){
                res = min(res,arr[low]);
                low = mid+1;
            }
            else{
                high = mid-1;
                res = min(res,arr[mid]);
            }
        }
        return res;
    }
};