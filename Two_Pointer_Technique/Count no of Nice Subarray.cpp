class Solution {
public:
    int fungoal(vector<int>& nums, int k){
        int n = nums.size();
        int l = 0;
        int r = 0;
        int sum = 0;
        int cnt = 0;
        if(k < 0)    return 0;
        while(r < n){
            sum += (nums[r] % 2);
            while(sum > k){
                sum = sum - (nums[l] % 2);
                l++;
            }
            cnt = cnt + (r-l+1);
            r = r + 1;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return fungoal(nums, k) 
             - fungoal(nums, k - 1);
    }
};