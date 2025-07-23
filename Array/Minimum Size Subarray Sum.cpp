class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int min_len = INT_MAX;  //Error
        int start = 0, end = 0;
        for(; end<n; end++){
            sum += nums[end];
            // if(sum >= target){
            //     min_len = min(min_len,i+1);
            // }
            while(sum>=target){
                min_len = min(min_len,end - start + 1);
                sum -= nums[start];
                start++;
            }
        }
        return (min_len == INT_MAX) ? 0 : min_len;
    }
};