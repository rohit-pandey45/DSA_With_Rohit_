class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0;
        int r = 0;
        int cnt = 0;
        vector<int> hash(256);
        int sind = -1;
        int minl = 1e9;
        int n = s.size();
        int m = t.size();
        for(int i = 0; i < m; i++){
            hash[t[i]]++;
        }
        while(r < n){
            if(hash[s[r]] > 0)  cnt++;
            hash[s[r]]--;
            while(cnt == m){
                if(r - l + 1 < minl){
                    minl = r - l + 1;
                    sind = l;
                }
                hash[s[l]]++;
                if(hash[s[l]] > 0)  cnt--;  
                l++;            
            }
            r++;
        }
        return sind == -1 ? "" : s.substr(sind,minl);
    }
};