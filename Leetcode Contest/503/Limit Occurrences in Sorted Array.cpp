class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        vector<int> ans;
        // int index = 0;
        for(int i = 0; i<n; i++){
            if(mpp[nums[i]] < k){
                ans.push_back(nums[i]);
                // index++;
                mpp[nums[i]]++;
            }
        }
        return ans;
        
        
    }
};©leetcode