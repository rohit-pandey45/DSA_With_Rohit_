class Solution {
public:
    void func(int index, vector<int>& arr,vector<int>& ds,vector<vector<int>>& ans) {

        ans.push_back(ds);

        for (int i = index; i < arr.size(); i++) {

            // Skip duplicates at the same level
            if (i > index && arr[i] == arr[i - 1])
                continue;

            ds.push_back(arr[i]);

            func(i + 1, arr, ds, ans);

            ds.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& arr) {

        sort(arr.begin(), arr.end());

        vector<vector<int>> ans;
        vector<int> ds;

        func(0, arr, ds, ans);

        return ans;
    }
};