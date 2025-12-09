class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int n = s.size();
        int len = 0;
        int maxlen = 0;
        int l = 0;
        int r = 0;
        unordered_map<char,int> mpp;
        bool found = false;
        while(r < n){
            mpp[s[r]]++;
            while(mpp.size() > k){
                mpp[s[l]]--;
                if(mpp[s[l]] == 0){
                    mpp.erase(s[l]);
                }
                l++;
            }
            if(mpp.size() == k){
                found = true;
                len = r-l+1;
                maxlen = max(len,maxlen);
            }
            r++;
        }
        return found ? maxlen : -1;
        
    }
};