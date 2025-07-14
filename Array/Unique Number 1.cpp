class Solution {
  public:
    int findUnique(vector<int> &arr) {
        int n = arr.size();
        //Concept of XOR : 1. a^a = 0; 2. a^0 = a
        int ans = 0;
        for (int i = 0; i<n; i++){
            ans = ans ^ arr[i];
        }
        return ans;
    }
};