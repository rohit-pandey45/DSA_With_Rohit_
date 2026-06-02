// User function Template for C++
class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        int n = arr.size();
        int low = 0;
        int high = n-1;
        int ind = -1;
        while(low <= high){
            int mid = low + ((high - low)/2);
            if(arr[mid] >= x){
                ind = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ind;
    }
};