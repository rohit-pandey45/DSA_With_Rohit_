class Solution {
  public:
    void generate(string s, int index, string curr, vector<string>& ans){
        //Base Case
        if(s.size() == index){
            if(curr != " ")     ans.push_back(curr);
            return;
        }
        generate(s, index + 1, curr, ans);
        curr.push_back(s[index]);
        generate(s, index + 1, curr, ans);
        curr.pop_back();
    }
    vector<string> AllPossibleStrings(string s) {
        int n = s.size();
        vector<string> ans;
        int index = 0;
        generate(s, index, "", ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};