class Solution {
public:
    int climbStairs(int n) {
        if(n<=1)  return n;
        int prev_two = 1;
        int prev_one = 1;
        int curr = 0;
        for(int i = 1 ; i<n; i++){
            curr = prev_one + prev_two;
            prev_two = prev_one;
            prev_one = curr;
        }
        return curr;
    }
};