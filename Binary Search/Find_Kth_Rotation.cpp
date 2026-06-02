class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int n = arr.size();
        int low = 0;
        int high = n-1;
        //int k = 0;
        while(low < high){
            int mid = low + ((high - low)/2);
            if(arr[mid] > arr[high]){
                low = mid+1;
            }
            else{
                high = mid;
            }
        }
        return low;
    }
};
