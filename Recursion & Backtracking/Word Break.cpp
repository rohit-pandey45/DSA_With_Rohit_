class Solution {
public:
    unordered_set<string> dict;
    vector<int> memo;

    bool solve(int idx, string &s) {

        if (idx == s.size())
            return true;

        if (memo[idx] != -1)
            return memo[idx];

        string curr = "";

        for (int i = idx; i < s.size(); i++) {

            curr += s[i];

            if (dict.count(curr) && solve(i + 1, s))
                return memo[idx] = true;
        }

        return memo[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {

        dict = unordered_set<string>(wordDict.begin(),
                                     wordDict.end());

        memo.assign(s.size(), -1);

        return solve(0, s);
    }
};
// class Solution {
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {

//         unordered_set<string> st(wordDict.begin(), wordDict.end());

//         int n = s.size();

//         vector<bool> dp(n + 1, false);
//         dp[n] = true;

//         for (int i = n - 1; i >= 0; i--) {

//             string curr = "";

//             for (int j = i; j < n; j++) {

//                 curr += s[j];

//                 if (st.count(curr) && dp[j + 1]) {
//                     dp[i] = true;
//                     break;
//                 }
//             }
//         }

//         return dp[0];
//     }
// };