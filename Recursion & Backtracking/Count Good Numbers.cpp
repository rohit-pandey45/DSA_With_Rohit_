class Solution {
public:
    long long mod = 1e9 + 7;
    long long power(long long x, long long n){
        long long res = 1;
        while(n > 0){
            if(n % 2 == 1){
                res = (res * x) % mod;
                n = n - 1;
            }
            else{
                x = (x*x) % mod;
                n = n/2;
            }
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        long long evenplaces = (n+1)/2;
        long long oddplaces = n/2;
        long long ans = (power(5, evenplaces) * (power(4, oddplaces))) % mod;
        return ans;
    }
};