class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        int n = arr.size();
        vector<int> ans;        //For returning the desired result
        unordered_map<int,int> mpp;     // SC : O(n)
        int flag = 0;           
        for (int i = 0; i<n; i++){
            mpp[arr[i]]++;          //String each element along with its frequency
            if(i>=k-1){             //Condition For Checking Every Window one by one
                ans.push_back(mpp.size());    
    //The size of map will be the no of distinct elements in that particular window
                mpp[arr[flag]]--;
                if(mpp[arr[flag]] == 0){
                    mpp.erase(arr[flag]);       
    //Erase the occurence of the elements from the starting so that the new window can be formed
                }
                flag++;     //Incrementing Flag
            }
        }
        return ans;
    }
};