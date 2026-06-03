class Solution {
public:
    void findsum(int sum, int first, vector<int>& nums, int k, vector<vector<int>>& ans){
        //Base Case
        if(sum == 0 && nums.size() == k){
            ans.push_back(nums);
            return;
        }
        if(sum <= 0 && nums.size() > k){
            return;
        }

        //Recursive Part
        for(int i = first; i<=9; i++){
            if(i <= sum){
                nums.push_back(i);
                findsum(sum - i, i+1, nums, k, ans);
                nums.pop_back();
            }
            else{
                break;
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> nums;
        findsum(n,1,nums,k,ans);
        return ans;
    }
};