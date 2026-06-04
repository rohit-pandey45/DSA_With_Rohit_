class Solution {
public:
    using ll = long long;

    struct Node {
        ll cnt;
        ll wav;
    };

    string s;
    Node dp[20][11][11][20];
    bool vis[20][11][11][20];

    Node dfs(int pos, bool tight,
             bool started,
             int prev2,
             int prev1,
             int len) {

        if (pos == s.size()) {
            return {1, 0};
        }

        if (!tight && vis[pos][prev2 + 1][prev1 + 1][len])
            return dp[pos][prev2 + 1][prev1 + 1][len];

        int limit = tight ? (s[pos] - '0') : 9;

        Node res = {0, 0};

        for (int d = 0; d <= limit; d++) {

            bool ntight = tight && (d == limit);

            if (!started && d == 0) {
                Node child =
                    dfs(pos + 1, ntight, false, -1, -1, 0);

                res.cnt += child.cnt;
                res.wav += child.wav;
            }
            else {
                if (!started) {
                    Node child =
                        dfs(pos + 1, ntight, true,
                            -1, d, 1);

                    res.cnt += child.cnt;
                    res.wav += child.wav;
                }
                else {
                    int add = 0;

                    if (len >= 2) {
                        if ((prev1 > prev2 && prev1 > d) ||
                            (prev1 < prev2 && prev1 < d))
                            add = 1;
                    }

                    int nprev2 = (len >= 1 ? prev1 : -1);

                    Node child =
                        dfs(pos + 1, ntight, true,
                            nprev2, d, len + 1);

                    res.cnt += child.cnt;
                    res.wav += child.wav + add * child.cnt;
                }
            }
        }

        if (!tight) {
            vis[pos][prev2 + 1][prev1 + 1][len] = true;
            dp[pos][prev2 + 1][prev1 + 1][len] = res;
        }

        return res;
    }

    long long solve(long long n) {
        if (n < 0) return 0;

        s = to_string(n);
        memset(vis, 0, sizeof(vis));

        return dfs(0, true, false, -1, -1, 0).wav;
    }

    int totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};