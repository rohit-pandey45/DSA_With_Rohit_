// User function Template for C++

//Back-end complete function Template for C++

class Solution {
  public:
    long long solve(vector<int>& bt) {
        int n = bt.size();
        sort(bt.begin(),bt.end());
        long long t = 0;
        long long wt = 0;
        for(int i = 0; i< n; i++){
            wt += t;
            t += bt[i];
        }
        return wt/n;
        
    }
};