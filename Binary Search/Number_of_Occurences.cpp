class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        int n = arr.size();
        //Lower Bound
        int low = 0;
        int high = n-1;
        int ind1 = n;
        while(low <= high){
            int mid = low + ((high - low)/2);
            if(arr[mid] >= target){
                ind1 = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        // return ind;
        //Upper Bound
        low = 0;
        high = n-1;
        int ind2 = n;
        while(low <= high){
            int mid = low + ((high - low)/2);
            if(arr[mid] > target){
                ind2 = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        // return ind;
        return ind2 - ind1;
    }
};
