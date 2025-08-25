class Solution {
  public:
    int countWays(int n) {
        //Same Concept As Fibonacci Number
        if(n<=1)     return 1;
        int prev2 = 1;
        int prev1 = 1;
        int curr = 0;
        for(int i = 1; i<n; i++){
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
        
    }
};
