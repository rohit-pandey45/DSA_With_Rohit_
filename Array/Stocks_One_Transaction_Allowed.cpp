class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        // code here
        int n = prices.size();
        int maxProfit = 0;
        int mini = prices[0];
        for (int i = 1; i<n; i++){
            int cost = prices[i] - mini;
            maxProfit = max(maxProfit,cost);
            mini = min(mini,prices[i]);
        }
        return maxProfit;
    }
    
};
