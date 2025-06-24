class Solution {
  public:
    int minChar(string& s) {
        int n = s.length();
        string revs = s;
        reverse(revs.begin(),revs.end());
        
        string combined = s + "$" + revs;
        int k = combined.length();
        vector<int> lps(k,0);
        for (int i = 1; i<k; i++){
            int j = lps[i - 1];
            while( j>0 && combined[i] != combined[j]){
                j = lps[j-1];
            }
            if (combined[i] == combined[j]){
                j++;
            }
            lps[i] = j;
        }
        return n - lps.back();
        
    }
};
