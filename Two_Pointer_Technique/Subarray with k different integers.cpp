class Solution {
public:
    int fungoal(vector<int>& nums, int k){
        int n = nums.size();
        int l = 0;
        int r = 0;
        unordered_map<int,int> mpp;
        int cnt = 0;
        while(r < n){
            mpp[nums[r]]++;
            while(mpp.size() > k){
                mpp[nums[l]]--;
                if(mpp[nums[l]] == 0){
                    mpp.erase(nums[l]);
                }
                l++;
            }
            cnt = cnt + (r - l + 1);
            r++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return fungoal(nums, k) 
             - fungoal(nums, k - 1);
    }
};