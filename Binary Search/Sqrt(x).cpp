class Solution {
public:
    int mySqrt(int x) {
        //base Case
        if(x<2)     return x;
        int low = 1;
        int high = x/2;
        int ans = 0;
        while(low<=high){
            int mid = (low+high)/2;
            if((long long) mid * mid <= x){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return ans;
    }
};