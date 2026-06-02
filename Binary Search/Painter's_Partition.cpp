class Solution {
  public:
    int callPainter(vector<int>& arr, int k, int mid){
        int n = arr.size();
        int cnt = 1;
        int tym = 0;
        //int maxi = INT_MIN;
        for(int i = 0; i<n; i++){
            if(tym + arr[i] <= mid){
                tym += arr[i];
            }
            else{
                cnt++;
                tym = arr[i];
            }
            //maxi = max(maxi,tym);
        }
        return  cnt;
    }
    int minTime(vector<int>& arr, int k) {
        int n = arr.size();
        //Initialising Search Space
        int low = *max_element(arr.begin(),arr.end());
        int high = accumulate(arr.begin(),arr.end(),0);
        //Edges Case
        int ans = high;
        if(k == 1)  return ans;
        //Applying Binary Search
        while(low <= high){
            int mid = low + ((high - low)/2);
            int painters = callPainter(arr,k,mid);
            if(painters > k){
                low = mid + 1;
            }
            else{
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
        
    }
};