class Solution {
public:
    void findcombi(string digits, vector<string>& ans, string s, int ind, string combos[]){
        //Base Case
        if(ind == digits.size()){
            ans.push_back(s);
            return;
        }

        //Recursive approach
        int digit = digits[ind] - '0';
        for(int i = 0; i<combos[digit].size(); i++){
            findcombi(digits, ans, s+combos[digit][i], ind+1, combos);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string combos[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        findcombi(digits,ans,"",0,combos);
        return ans;
    }
};