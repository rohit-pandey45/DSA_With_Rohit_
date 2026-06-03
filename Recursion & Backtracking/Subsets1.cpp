class Solution {
  public:
    void func(int index, int runSum, vector<int>& arr, vector<int>& ans){
        if(index == arr.size()){
            ans.push_back(runSum);
            return;
        }
        func(index+1, runSum + arr[index], arr, ans);
        func(index+1, runSum, arr, ans);
    }
    vector<int> subsetSums(vector<int>& arr) {
        vector<int> ans;
        func(0, 0, arr, ans);
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};