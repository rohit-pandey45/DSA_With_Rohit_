class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n,true);
        if(n > 0) prime[0] = false;
        if(n > 1) prime[1] = false;

        for(int i = 2; i*i<n; i++){
            if(prime[i]){
                for(int j = i*i; j<n; j+=i){
                    prime[j] = false;
                }
            }
        }
        int cntPrime = 0;
        for(bool it : prime){
            if(it)   cntPrime++;
        }

        return cntPrime;
    }
};