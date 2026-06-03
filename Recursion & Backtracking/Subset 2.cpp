class Solution {
  public:
    void findsubset(int index, vector<vector<int>>& ans, vector<int>& ls, vector<int>& arr){
        if(index == arr.size()){
            ans.push_back(ls);
            return;
        }
        ls.push_back(arr[index]);
        findsubset(index+1,ans,ls,arr);
        ls.pop_back();
        findsubset(index+1,ans,ls,arr);
    }
    vector<vector<int>> subsets(vector<int>& arr) {
        vector<vector<int>> ans;
        vector<int> ls;
        findsubset(0,ans,ls,arr);
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};