class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        int longseq = INT_MIN;
        int curlen = 0;
        int max_ele = *max_element(arr.begin(),arr.end());
        vector<int> hash(max_ele+1, 0);
        for(int i = 0; i<arr.size(); i++){
            hash[arr[i]]++;
        }
        for(int i = 0; i<hash.size(); i++){
            if(hash[i] == 0){
                curlen = 0;
                continue;
            }
            curlen++;
            longseq = max(longseq,curlen);
        }
        return longseq;
        
    }
};