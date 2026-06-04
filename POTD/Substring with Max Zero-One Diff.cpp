class Solution {
  public:
    int maxSubstring(string &s) {
        int n = s.size();
        int curr = 0;
        int maxi = -1;
        for(char ch : s){
            int val = (ch == '0') ? 1 : -1;
            curr = max(val,curr+val);
            maxi = max(maxi,curr);
        }
        return maxi;
        
    }
};