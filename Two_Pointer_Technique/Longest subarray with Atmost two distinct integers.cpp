class Solution {
  public:
    int totalElements(vector<int> &arr) {
        //Brute
        // int n = arr.size();
        // int len = 0;
        // int maxlen = 0;
        // for(int i = 0; i<n; i++){
        //     set<int> st;
        //     for(int j = i; j<n; j++){
        //         st.insert(arr[j]);
        //         if(st.size() <= 2){
        //             len = j-i+1;
        //             maxlen = max(maxlen,len);
        //         }
        //         else{
        //             break;
        //         }
        //     }
        // }
        // return maxlen;
        
        //Optimal
        int n = arr.size();
        int len = 0;
        int maxlen = 0;
        int l = 0;
        int r = 0;
        unordered_map<int,int> mpp;
        while(r < n){
            mpp[arr[r]]++;
            while(mpp.size() > 2){
                mpp[arr[l]]--;
                if(mpp[arr[l]] == 0){
                    mpp.erase(arr[l]);
                }
                l++;
            }
            if(mpp.size() <= 2){
                len = r-l+1;
                maxlen = max(len,maxlen);
            }
            r++;
        }
        return maxlen;
        
    }
};