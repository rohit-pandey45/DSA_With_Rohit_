class Solution {
public:
    double myPow(double x, int n) {
        long long nn = n;
        double ans = 1.0;
        if (nn < 0) {
            nn = -nn;
            x = 1 / x;
        }
        while(nn>0){
            if(nn % 2 == 1){
                ans = ans*x;
                nn = nn-1;
            }
            else{
                nn = nn/2;
                x = x*x;
            }
        }
        return ans;
    }
};