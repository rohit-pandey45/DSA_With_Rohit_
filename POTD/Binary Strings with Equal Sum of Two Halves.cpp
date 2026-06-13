class Solution {
public:
    const long long MOD = 1000000007;

    long long power(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    int computeValue(int n) {
        vector<long long> fact(2 * n + 1, 1);

        for (int i = 1; i <= 2 * n; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }

        long long numerator = fact[2 * n];
        long long denominator =
            (fact[n] * fact[n]) % MOD;

        long long ans =
            numerator * power(denominator, MOD - 2) % MOD;

        return (int)ans;
    }
};

// class Solution {
//   public:
//     long long modulo = 1e9;
    
//     bool check(string s) {
//     int len = s.size();
//     int n = len / 2;

//     int left = 0, right = 0;

//     for (int i = 0; i < n; i++) {
//         left += s[i] - '0';
//     }

//     for (int i = n; i < len; i++) {
//         right += s[i] - '0';
//     }

//     return left == right;
// }
    
//     void solve(int n, vector<string>& ans, string s){
//         if(s.size() == 2*n){
//             if(check(s)){
//                 ans.push_back(s);
//                 return;
//             }
//         }
        
//         solve(n,ans,s+'0');
//         solve(n,ans,s+'1');
//     }
//     int computeValue(int n) {
//         vector<string> ans;
//         solve(n,ans,"");
//         return ans.size();
        
//     }
// };