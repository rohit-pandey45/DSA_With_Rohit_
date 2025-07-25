class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        int n = arr.size();
        int ind = -1;
        //Find the Breaking Point
        for(int i = n-2; i>=0; i--){
            if(arr[i]<arr[i+1]){
                ind = i;
                break;
            }
        }
        //Edge Case
        if(ind == -1){
            reverse(arr.begin(),arr.end());
            return;             //Dont Forget to Give this return statement otherwise the next for loop will also get executed
        }
        //Finding the next Permutation
        for(int i = n-1; i>ind; i--){
            if(arr[i]>arr[ind]){
                swap(arr[i],arr[ind]);
                break;
            }
        }
        reverse(arr.begin()+ind+1,arr.end());
        
    }
};