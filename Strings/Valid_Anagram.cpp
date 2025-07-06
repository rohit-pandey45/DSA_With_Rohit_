class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freq(26,0);
        if (s.length() != t.length()){
            return false;
        }
        for (auto ch : s){
            freq[ch - 'a']++;
        }
        for(auto ch : t){
            freq[ch - 'a']--;
        }
        for (int i = 0; i<26; i++){
            if(freq[i] != 0){
                return false;
            }
        }
        return true;
    }
};