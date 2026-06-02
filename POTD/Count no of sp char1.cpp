class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        int cnt = 0;
        unordered_set<int> st;
        for(int i = 0; i<n; i++){
            st.insert(word[i]);
        }
        for(char ch = 'a'; ch <= 'z'; ch++){
            if(st.count(ch) && st.count(ch-'a'+'A')){
                cnt++;
            }
        }
        return cnt;
    }
};