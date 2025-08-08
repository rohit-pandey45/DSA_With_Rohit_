class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int i = 0;  //For Arrival
        int j = 0;  //For Departure
        int cnt = 0;
        int maxcnt = 0;
        int n = arr.size();
        while(i<n){
            if(arr[i] <= dep[j]){
                cnt++;
                i++;
            }
            else{
                cnt--;
                j++;
            }
            maxcnt = max(maxcnt,cnt);
        }
        return maxcnt;
    }
};
