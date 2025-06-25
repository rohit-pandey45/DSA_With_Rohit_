// User function Template for C++
class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int low = 0;
        int high = n-1;
        int count = 0;
        while(low<high){
            int sum = arr[low]+arr[high];
            if(sum>=target){
                high--;
            }
            else{
                count += (high-low);
                low++;
            }
        }
        return count;
    }
};
