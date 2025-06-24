// User function Template for C++
class Solution {
  public:
    // Function to find hIndex
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int n = citations.size();
        int i = 1;
        
        for (i; i<=n; i++){
            if (citations[n-i] < i){
                
                break;
            }
        }
        return i-1;
        
        
    }
};