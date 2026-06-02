class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int d = -1;
        for(int i = 1; i<n; i++){
            //Check for Rotated
            if(nums[i-1] > nums[i]){
                d = i;
                break;
            }
        }
        //If array already Sorted Return and not rotated return false;
        if(d == -1) return true;
        //else if rotated then generated the original array
        reverse(nums.begin(),nums.begin()+d);
        reverse(nums.begin()+d,nums.end());
        reverse(nums.begin(),nums.end());
        //Now check wheteher array was sorted or not
        for(int i = 1; i<n; i++){
            if(nums[i-1] > nums[i]){
                return false;
            }
        }
        return true;
    }
};