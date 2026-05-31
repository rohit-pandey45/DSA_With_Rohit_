class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        int cnt = 0;
        vector<int> lastloweroccurence(26,-1);
        vector<int> firstupperoccurence(26,-1);
        for(int i = 0; i<n; i++){
            char ch = word[i];
            if(islower(ch)){
                lastloweroccurence[ch-'a'] = i;
            }
            else{
                int ind = ch - 'A';
                if(firstupperoccurence[ind] == -1){
                    firstupperoccurence[ind] = i;
                }
            }
        }
        for(int i = 0; i<26; i++){
            if(lastloweroccurence[i] != -1 
                && firstupperoccurence[i] != -1 
                && lastloweroccurence[i] < firstupperoccurence[i]){
                cnt++;
            }
        }
        return cnt;
    }
};