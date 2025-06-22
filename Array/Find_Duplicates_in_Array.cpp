class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        if(n <= 1) return res;
        // if (nums[0] == nums[1]) res.push_back(nums[0]);
        // if(nums[n-1] == nums[n-2]) res.push_back(nums[n-1]);
        sort(nums.begin(),nums.end());
        // int sum = 0;
        for(int i = 1; i<n; i++){
            if(nums[i] == nums[i-1]){
                if(res.empty() || res.back() != nums[i]) {
                    res.push_back(nums[i]);
                }
            }
        }
        
        return res;
    }
};