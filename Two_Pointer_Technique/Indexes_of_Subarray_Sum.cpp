class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        int n = arr.size();
        int sum = 0;
        int left_most = 0;
        for(int right_most = 0; right_most<n; right_most++){
            sum += arr[right_most];
            //If sum exceeds target
            while(sum>target && left_most<=right_most){
                sum -= arr[left_most];
                left_most++;
            }
            if(sum == target){
                return{left_most+1,right_most+1};   //1-based indexing
            }
        }
        //If No Subarray Found
        return {-1};
    }
};