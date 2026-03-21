class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ind = 0;
        while(low <= high){
            int mid = low + ((high - low)/2);
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                // ind = mid-1;
                high = mid-1;
                
            }
            else{
                // ind = mid+1;
                low = mid+1;
                
            }
        }
        return low;
    }
};