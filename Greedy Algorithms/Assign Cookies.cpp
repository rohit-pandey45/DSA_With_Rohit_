class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int l = 0;  //s
        int r = 0;  //g
        while(l < m && r < n){
            if(g[r] <= s[l]){
                r++;
            }
            l++;
        }
        return r;

    }
};