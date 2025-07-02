class Solution {
  public:
    int maxLen(vector<int> &arr) {
        int n = arr.size();
        if(n == 0 || n == 1)    return 0;
        int max_len = 0;
        int sum = 0;
        unordered_map<int,int> mpp;
        for(int i = 0; i<n; i++){
            if(arr[i] == 0){
                arr[i] = -1;
            }
            sum += arr[i];
            if(sum == 0){
                max_len = i+1;
            }
            if(mpp.find(sum) != mpp.end()){
                max_len = max(max_len,i-mpp[sum]);
            }
            else{
                mpp[sum] = i;
            }
        }
        return max_len;
        
    }
};