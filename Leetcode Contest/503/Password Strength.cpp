class Solution {
public:
    int passwordStrength(string password) {
        int s = password.size();
        int length = 0;
        unordered_set<char> st;
        for(int i = 0; i<s; i++){
            st.insert(password[i]);
        }
        for(char c : st){
            if(c >= 'a' && c <= 'z'){
                length += 1;
            }
            else if(c >= 'A' && c <= 'Z'){
                length = length + 2;
            }
            else if(c >= '0' && c <= '9'){
                length = length + 3;
            }
            else if(c == '!' || c == '@' || c == '#' || c == '$'){
                length = length + 5;
            }
        }
        return length;
    }
};©leetcode