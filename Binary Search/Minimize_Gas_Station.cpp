class Solution {
  private:
    int GasStation(vector<int> &stations, int k, double mid){
        int n = stations.size();
        int cnt = 0;
        for(int i = 1; i<n; i++){
            double minDist = (stations[i] - stations[i-1]);
            cnt += (int)(minDist/mid);
            // if((stations[i] - stations[i-1]) == minDist * mid){
            //     minDist--;
            // }
            // cnt += minDist;
        }
        return cnt;
    }
  public:
    double minMaxDist(vector<int> &stations, int k) {
        int n = stations.size();
        //Initialise Search Space
        double low = 0;
        double high = 0;

        for(int i = 1; i < n; i++) {
            high = max(high, (double)(stations[i] - stations[i-1]));
        }
        
        // int low = 0;
        // int high = *max_element(stations.begin(),stations.end());
        //Applying Binary Search
        while(high - low > 1e-6){
            double mid = low + ((high - low)/2.0);
            int ans = GasStation(stations,k,mid);
            if(ans > k){
                low = mid;
            }
            else{
                high = mid;
            }
        }
        return high;
        
    }
};