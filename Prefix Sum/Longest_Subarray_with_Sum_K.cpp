class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<int,int> mpp;
        int n = arr.size();
        int sum = 0;
        int max_len = 0;
        for(int i = 0; i<n; i++){
            sum += arr[i];
            //If the whole array combined has the sum k
            if(sum == k){
                max_len = i+1;
            }
            //If a part of the array has sum k.
            int more = sum - k;
            if(mpp.find(more) != mpp.end()){
                max_len = max(max_len,i-mpp[more]);
            }
            
            //Storing only the first occurence of the element along with its index.
            if(mpp.find(sum) == mpp.end()){
                mpp[sum] = i;
            }
        }
        return max_len;
    }
};