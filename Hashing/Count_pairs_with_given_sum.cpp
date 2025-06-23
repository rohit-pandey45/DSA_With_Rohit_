class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int count = 0;
        unordered_map<int,int> mpp;
        for(int num : arr){
            int more = target - num;
            if(mpp.count(more)){
                count += mpp[more];
            }
            mpp[num]++;
        }
        return count;
        
    }
};