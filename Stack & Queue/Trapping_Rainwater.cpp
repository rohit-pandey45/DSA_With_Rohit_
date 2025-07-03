class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int n = arr.size();
        int left_max = 0;
        int right_max = 0;
        int total = 0;
        int left = 0;
        int right = n-1;
        while(left<right){
            if(arr[left]<=arr[right]){
                if(left_max>arr[left]){
                    total += left_max - arr[left];
                }
                else{
                    left_max = arr[left];
                }
                left++;
            }
            else{
                if(right_max>arr[right]){
                    total += right_max - arr[right];
                }
                else{
                    right_max = arr[right];
                }
                right--;
            }
        }
        return total;
    }
};