class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        vector<int> leftsum;
        vector<int> rightsum;
        int left = 0;
        int right = 0;
        for(int i = 0; i<n; i++){
            leftsum.push_back(left);
            left += nums[i];
        }
        for(int i = n-1; i >= 0; i--){
            rightsum.push_back(right);
            right += nums[i];
        }
        for(int i = 0; i<n; i++){
            ans.push_back(abs(leftsum[i] - rightsum[n-1-i]));
        }
        return ans;
    }
};