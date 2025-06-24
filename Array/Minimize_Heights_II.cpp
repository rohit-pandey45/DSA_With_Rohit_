class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int ans = arr[n-1] - arr[0];
        int mini = arr[0]+k;
        int maxi = arr[n-1]-k;
        int mi = 0, ma = 0;
        for (int i = 0; i<n; i++){
            mi = min(mini,arr[i+1]-k);
            ma = max(maxi,arr[i]+k);
            if (mi<0){
                continue;
            }
            ans = min(ans, ma-mi);
        }
     return ans;
    }
   
};