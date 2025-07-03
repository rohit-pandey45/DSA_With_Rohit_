class Solution {

  public:
    int maxWater(vector<int> &arr) {
        int n = arr.size();
        int left = 0;
        int right = n-1;
        int max_water = 0;
        while(left<right){
            int height = min(arr[left],arr[right]);
            int width = right - left;
            int area = height*width;
            max_water = max(max_water,area);
            if(arr[left]<=arr[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return max_water;
        
    }
};