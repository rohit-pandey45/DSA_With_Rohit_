class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();
        vector<long long> len(n + 1, 0);

        const long long INF = 1e18;

        for (int i = 0; i < n; i++) {
            char c = s[i];

            if ('a' <= c && c <= 'z') {
                len[i + 1] = min(INF, len[i] + 1);
            }
            else if (c == '*') {
                len[i + 1] = max(0LL, len[i] - 1);
            }
            else if (c == '#') {
                len[i + 1] = min(INF, len[i] * 2);
            }
            else { // '%'
                len[i + 1] = len[i];
            }
        }

        if (k >= len[n]) return '.';

        for (int i = n - 1; i >= 0; i--) {
            char c = s[i];

            if ('a' <= c && c <= 'z') {
                if (k == len[i]) {
                    return c;
                }
            }
            else if (c == '*') {
                // nothing to do
            }
            else if (c == '#') {
                long long L = len[i];
                if (L > 0) k %= L;
            }
            else { // '%'
                long long L = len[i];
                k = L - 1 - k;
            }
        }

        return '.';
    }
};