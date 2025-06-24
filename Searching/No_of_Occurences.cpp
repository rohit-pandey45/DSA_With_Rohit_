class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        int n = arr.size();
        map<int,int> mpp;
        for (int i = 0; i<n; i++){
            if (arr[i] == target){
                mpp[arr[i]]++;;
            }
        }
        return mpp[target];
        
    }
};
