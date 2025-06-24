class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        int low = 0; 
        int high = n - 1;
        while (high>=0 && low<m){
            if (a[high]>b[low]){
                swap(a[high],b[low]);
                low++;
                high--;
            }
            else{
                break;
            }
        } 
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
    }
};