class Solution {
  public:
    vector<int> search(string& pat, string& txt) {
       int k = pat.size();
       vector<int> lps(k,0), res;
       for (int i = 1, len = 0; i<k;){
            if (pat[i] == pat[len]){
                lps[i++] = ++len;
            }
            else if (len){
                len = lps[len - 1];
            }
            else{
                lps[i++] = 0;
            }
       }
       for (int i = 0, j = 0; i<txt.size();){
           if (txt[i] == pat[j]){
               i++;
               j++;
               if (j == k){
                   res.push_back(i-j);
                   j = lps[j-1];
               }
           }else if(j) {
               j = lps[j-1];
           }
           else{
               i++;
           }
       }   
       return res;
        
    }
};