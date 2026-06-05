class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }

    string lexicographicallySmallest(string s, int k) {
        int n = s.size();

        if (isPowerOfTwo(n))
            k /= 2;
        else
            k *= 2;

        if (k >= n) return "-1";

        vector<char> st;
        int remove = k;

        for (char c : s) {
            while (!st.empty() && remove > 0 && st.back() > c) {
                st.pop_back();
                remove--;
            }
            st.push_back(c);
        }

        while (remove > 0) {
            st.pop_back();
            remove--;
        }

        string ans(st.begin(), st.end());

        if (ans.empty()) return "-1";
        return ans;
    }
};