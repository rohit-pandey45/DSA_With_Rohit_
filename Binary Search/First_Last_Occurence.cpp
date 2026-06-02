class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        int low = 0;
        int high = n-1;

        int firstind = -1;
        int secondind = -1;
        //First Occurence
        while(low <= high){
            int mid = low + ((high - low)/2);
            if(nums[mid] < target){
                low = mid+1;
            }
            else if(nums[mid] > target){
                high = mid-1;
            }
            else{
                firstind = mid;
                high = mid-1;
            }
        }

        //Last Occurences
        low = 0;
        high = n-1;
        while(low <= high){
            int mid = low + ((high - low)/2);
            if(nums[mid] < target){
                low = mid+1;
            }
            else if(nums[mid] > target){
                high = mid-1;
            }
            else{
                secondind = mid;
                low = mid+1;
            }
        }
        return {firstind,secondind};
    }
};