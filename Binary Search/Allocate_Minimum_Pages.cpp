class Solution {
  public:
    int noofstudent(vector<int> &arr, int maxstu){
        int n = arr.size();
        int stu = 1;
        int noofpages = 0;
        for(int i = 0; i<n; i++){
            if(arr[i]+noofpages <= maxstu){
                noofpages += arr[i];
            }
            else{
                stu++;
                noofpages = arr[i];
            }
        }
        return stu;
    }
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if (n<k) return -1;
        int low = *max_element(arr.begin(),arr.end());
        int high = accumulate(arr.begin(),arr.end(),0);
        while(low<=high){
            int mid = (low+high)/2;
            int noofstu = noofstudent(arr,mid);
            if(noofstu<=k){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
        
    }
};