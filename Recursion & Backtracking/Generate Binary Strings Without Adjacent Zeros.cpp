class Solution {
public:
    void generate(int n, string s, vector<string>& ans){
        //Base Case(When to Terminate)
        if(s.size() == n){
            ans.push_back(s);
            return;
        }
        generate(n, s + "1", ans);
        if(s.empty() || s.back() != '0'){
            generate(n, s + "0", ans);
        }
    }
    vector<string> validStrings(int n) {
        vector<string> ans;
        generate(n,"",ans);
        return ans;
    }
};