class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        int i = 0, j = 0;
        int minLen = INT_MAX;
        int startIndex = -1;

        while (i < n) {
            // Move forward in S to match T
            if (s[i] == t[j]) {
                j++;
            }

            // If we matched all of T
            if (j == m) {
                int end = i;  // ending index of window

                // Now move backward to shrink window
                j = m - 1;
                int k = i;
                while (k >= 0) {
                    if (s[k] == t[j]) {
                        j--;
                    }
                    if (j < 0) break;
                    k--;
                }

                // Now window is from k to end
                if (end - k + 1 < minLen) {
                    minLen = end - k + 1;
                    startIndex = k;
                }

                // Reset j to 0 and continue forward from k+1
                j = 0;
                i = k + 1;
            }

            i++;
        }

        if (startIndex == -1) return "";
        return s.substr(startIndex, minLen);
    }
};
