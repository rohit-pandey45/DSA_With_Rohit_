class Solution {
public:
    struct Node {
        long long cnt;
        long long wav;
    };

    string s;
    Node memo[17][17][11][11];
    bool vis[17][17][11][11];

    Node dfs(int pos, bool tight, int len,
             int prev2, int prev1) {

        if (pos == (int)s.size()) {
            return {1, 0};
        }

        if (!tight && vis[pos][len][prev2][prev1]) {
            return memo[pos][len][prev2][prev1];
        }

        int limit = tight ? s[pos] - '0' : 9;

        long long totalCnt = 0;
        long long totalWav = 0;

        for (int d = 0; d <= limit; d++) {
            bool ntight = tight && (d == limit);

            if (len == 0 && d == 0) {
                Node child = dfs(pos + 1, ntight, 0, 10, 10);

                totalCnt += child.cnt;
                totalWav += child.wav;
            } else {
                int add = 0;

                if (len >= 2) {
                    if ((prev1 > prev2 && prev1 > d) ||
                        (prev1 < prev2 && prev1 < d))
                        add = 1;
                }

                int nprev2 = (len == 1 ? prev1 : prev1);
                int nprev1 = d;

                Node child = dfs(
                    pos + 1,
                    ntight,
                    len + 1,
                    nprev2,
                    nprev1
                );

                totalCnt += child.cnt;
                totalWav += child.wav + 1LL * add * child.cnt;
            }
        }

        Node ans = {totalCnt, totalWav};

        if (!tight) {
            vis[pos][len][prev2][prev1] = true;
            memo[pos][len][prev2][prev1] = ans;
        }

        return ans;
    }

    long long calc(long long n) {
        if (n <= 0) return 0;

        s = to_string(n);
        memset(vis, 0, sizeof(vis));

        return dfs(0, true, 0, 10, 10).wav;
    }

    long long totalWaviness(long long num1, long long num2) {
        return calc(num2) - calc(num1 - 1);
    }
};