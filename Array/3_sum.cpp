// User function Template for C++
class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        vector<vector<int>> ans;
        int n = arr.size();
        for(int i = 0; i<n; i++){
        
            int j = i+1;
            
            while(j<n){
                int k = j+1;
                while(k<n){
                    if (arr[i]+arr[j]+arr[k] == 0){
                        ans.push_back({i,j,k});
                    }
                    k++;
                }
                j++;
            }
        }
        return ans;
        
    }
};