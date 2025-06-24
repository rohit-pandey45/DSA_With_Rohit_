// User function Template for C++

class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        map<string,vector<string>> m;
        int n = arr.size();
        for(int i = 0; i<n; i++){
            string s = arr[i];
            sort(s.begin(),s.end());
            m[s].push_back(arr[i]);
        }
        vector<vector<string>> ans(m.size());
        int index = 0;
        for(auto x : m){
            
            auto v = x.second;
            for(int i = 0; i<v.size(); i++){
                ans[index].push_back(v[i]);
            }
            index++;
            
        }
        return ans;
    }
};