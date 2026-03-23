class Solution {
  private:
    long long power(int mid,int n, int m){
        long long ans = 1;
        for(int i = 0; i<n; i++){
            ans = ans*mid;
        }
        return ans;
    }
  public:
    int nthRoot(int n, int m) {
        int low = 0;
        int high = m;
        while(low <= high){
            int mid = low + ((high - low)/2);
            int val = power(mid,n,m);
            if(val == m){
                return mid;
            }
            else if(val>m){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return -1;
        
    }
};