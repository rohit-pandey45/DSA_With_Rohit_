class Solution {
  public:
    // Function to count the number of possible triangles.
    int countTriangles(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int count_tri = 0;
        for (int k = n-1; k>=2; k--){
            int i = 0;
            int j = k-1;
            while(i<j){
                if(arr[i]+arr[j]<=arr[k]){
                    i++;
                }
                else{
                    count_tri += (j-i);
    //if a[i]+a[j]>a[k] then a[i+1]+a[j] will aslo be > k
    //and so on.                    
                    j--;
                }
            }
        }
        return count_tri;
    }
};
