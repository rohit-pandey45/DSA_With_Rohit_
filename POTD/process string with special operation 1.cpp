class Solution {
public:
    string processStr(string s) {
        string result;
        int n = s.size();
        for(int i = 0; i<n; i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                result += s[i];
            }
            else if(s[i] == '*'){
                if(result.length()){
                    result.pop_back();
                }
            }
            else if(s[i] == '#'){
                result += result;
            }
            else if(s[i] == '%'){
                reverse(result.begin(),result.end());
            }
        }
        return result;
    }
};