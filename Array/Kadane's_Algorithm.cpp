class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Your code here
        int n = arr.size();
        int current_sum = 0;
        int maxi = INT_MIN;
        for (int i = 0; i<n; i++){
            current_sum += arr[i];
            maxi = max(current_sum,maxi);
            if (current_sum<0){
                current_sum = 0;
            }
        }
        return maxi;
    }
};