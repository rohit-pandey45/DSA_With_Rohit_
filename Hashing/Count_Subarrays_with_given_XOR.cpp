class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        int count = 0;
        int xr = 0;
        map<int,int> mpp;
        mpp[0] = 1;
        for(int i = 0; i<n; i++){
            xr = xr^arr[i];
            int x = xr^k;
            count  = count +mpp[x];
            mpp[xr]++;
        }
        return count;
    }
};