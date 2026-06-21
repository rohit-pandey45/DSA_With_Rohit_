class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int n = costs.size();
        int cnt = 0;
        for(int i = 0; i<n; i++){
            coins -= costs[i];
            if(coins < 0){
                break;
            }
            cnt++;
        }
        return cnt;
    }
};