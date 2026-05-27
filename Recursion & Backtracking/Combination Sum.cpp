class Solution {
public:
    void func(vector<int>& candidates, int target, vector<vector<int>> &ans,int ind,vector<int>& ds){
        int n = candidates.size();
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        if(ind == n) return ;
        if(candidates[ind] <= target){
            ds.push_back(candidates[ind]);
            func(candidates,target - candidates[ind],ans,ind,ds);
            ds.pop_back();
        }
        func(candidates,target,ans,ind+1,ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> ds;
        func(candidates,target,ans,0,ds);
        return ans;
    }
};