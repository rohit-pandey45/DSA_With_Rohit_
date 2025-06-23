class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        int n = arr.size();
        if (n == 1) return false;
        
        unordered_map<int,int> mpp;
        for(int i = 0; i<n; i++){
            int num = arr[i];
            int more = target - num;
            if(mpp.find(more) != mpp.end()){
                return true;        //if more is present in the map return true
            }
            mpp[num] = i;       //else store the value in the map
        }
        return false;
        
    }
};