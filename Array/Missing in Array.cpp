class Solution {
  public:
    int missingNum(vector<int>& arr) {
        //Approach - 1
        sort(arr.begin(),arr.end());
        int n = arr.size();
        for(int i = 0; i<n; i++){
            if(arr[i] == i+1){
                continue;
            }
            else{
                return i+1;
            }
        }
        return n+1;
        // int n = arr.size();
        // int sum = 0;
        // for(int i = 0; i<n; i++){
        //     sum += arr[i];
        // }
        // int totalsum = (n+1)*(n+2) / 2;
        
        // return totalsum - sum;
    }
};