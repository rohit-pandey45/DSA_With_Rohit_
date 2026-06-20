class Solution {
  public:
    int modString(string b, int mod) {
        int res = 0;
        for(char c : b) {
            res = (res * 10 + (c - '0')) % mod;
        }
        return res;
    }
    int getLastDigit(string& a, string& b) {
        if (b == "0") return 1;

        int last = a.back() - '0';

        vector<vector<int>> cycles = {
            {0},
            {1},
            {2,4,8,6},
            {3,9,7,1},
            {4,6},
            {5},
            {6},
            {7,9,3,1},
            {8,4,2,6},
            {9,1}
        };

        vector<int> cycle = cycles[last];
        int len = cycle.size();

        int exp = modString(b, len);

        if (exp == 0) return cycle[len - 1];
        return cycle[exp - 1];
        
    }
};