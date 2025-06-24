class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& arr) {
        int n = arr.size();
        vector<int> result;
        map<int,int> mpp;
        for (int i = 0; i<n; i++){
            mpp[arr[i]]++;
            if (mpp[arr[i]] == n/3+1){
                result.push_back(arr[i]);
            }
            if (result.size() == 2){            //n/3 + n/3 = 2n/3 
                break;
            }
        }
        sort(result.begin(),result.end());      //Increasing Format
        return result;
    }
};