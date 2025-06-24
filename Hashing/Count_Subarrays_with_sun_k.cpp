// User function Template for C++

class Solution {
  public:
    int countSubarrays(vector<int> &arr, int k) {
        //prefix sum
        int n = arr.size();
        unordered_map<int,int> mpp;
        mpp[0] = 1;             //Should always initalize
        int prefixsum = 0;
        int count = 0;
        for(int i = 0; i<n; i++){
            prefixsum += arr[i];        //calculate prefix sum
            int more = prefixsum - k;       //what needs to ab added to get k
            count += mpp[more];     //if more is in hash map then increment count
            mpp[prefixsum] += 1;        //add prefix sum along with its freq to tha hash map
        }
        return count;
    }
};