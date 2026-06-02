class Solution {
public:
    void generate(vector<int>& nums, int index, vector<int>& curr, vector<vector<int>>& ans){
        //Base Case
        if(nums.size() == index){
            ans.push_back(curr);
            return;
        }
        generate(nums, index+1, curr, ans);
        curr.push_back(nums[index]);
        generate(nums, index+1, curr, ans);
        curr.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        //Method 2
        vector<vector<int>> ans;
        vector<int> curr;
        generate(nums, 0, curr, ans);
        return ans;


        //Method 1
        // vector<vector<int>> ans;
        // int n = nums.size();
        // int subsets = 1<<n;
        // for(int num = 0; num < subsets; num++){
        //     vector<int> list;
        //     for(int i = 0; i<n; i++){
        //         if(num & (1<<i)){
        //             list.push_back(nums[i]);
        //         }
        //     }
        //     ans.push_back(list);
        // }
        // return ans;
    }
};