class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        int n = s.size();
        vector<int> lastIndex(256,-1);  //supports all ascii characters
        int maxlen = 0;
        int start = 0;
        for(int end = 0; end<n; end++){
            if(lastIndex[s[end]] >= start){
                start = lastIndex[s[end]]+1;
            }
            lastIndex[s[end]] = end;
            maxlen = max(maxlen,end-start+1);
        }
        return maxlen;
        
    }
};
