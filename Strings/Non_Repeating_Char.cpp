
class Solution {
  public:
    char nonRepeatingChar(string &s) {
        int size = s.length();
        int hash[26] = {0};
        for (int i = 0; i<size; i++){
            hash[s[i] - 'a']++;
        }
        for (int i = 0; i<size; i++){
            if(hash[s[i] - 'a'] == 1){
                return s[i];
            }
        }
        return '$';
        
    }
};