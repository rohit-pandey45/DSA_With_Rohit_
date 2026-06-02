class Solution {
public:
    void generate(int open, int close, int n, string s, vector<string>& result){
        //Base Case(Where Recursion should stop and return)
        if(s.size() == 2*n){
            result.push_back(s);
            return;
        }
        if(open < n){
            generate(open+1, close, n, s + "(", result);
        }
        if(close < open){
            generate(open, close+1, n, s + ")", result);
        }
        
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate(0, 0, n, "", result);
        return result;
    }
};