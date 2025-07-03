class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        int n = arr.size();
        int prefsum = 0;
        int totalsum = 0;
        int index = -1;
        for(int i = 0; i<n; i++){
            totalsum += arr[i];
        }
        for(int i = 0; i<n; i++){
            int suffsum = totalsum - prefsum - arr[i];
            if(prefsum == suffsum){
                return i;
            }
            prefsum += arr[i];
        }
        return index;
    }
};