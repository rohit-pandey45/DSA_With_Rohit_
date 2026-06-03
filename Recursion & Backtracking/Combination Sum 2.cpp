class Solution {
public:
    void func(vector<int>& candidates, int target, int index, vector<vector<int>>& ans, vector<int>& ls){
        int n = candidates.size();

        //Base Case
        if(target == 0){
            ans.push_back(ls);
            return;
        }
        if(index == n)  return;

        for(int i = index; i<n; i++){
            //Check for Duplicates
            if(i > index && candidates[i] == candidates[i-1]){
                continue;
            }
            //Check for larger value
            if(candidates[i] > target){
                break;
            }
            ls.push_back(candidates[i]);
            func(candidates, target - candidates[i], i+1, ans, ls);
            ls.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> ls;
        int index = 0;
        func(candidates, target, index, ans, ls);
        return ans;
    }
};