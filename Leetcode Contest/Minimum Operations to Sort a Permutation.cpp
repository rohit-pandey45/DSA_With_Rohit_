class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        //Edge Case
        if(n == 1)    return 0;
        int result = INT_MAX;
        int index = -1;
        for(int i = 0; i<n; i++){
            if (nums[i] == 0){
                index = i;
                break;
            }
        }
        bool increasing = true;
        bool decreasing = true;
        for(int i = 0; i<n; i++){
            if((nums[i]+1) % n != nums[(i+1) % n]){
                increasing = false;
            }
            if((nums[i]-1+n) % n != nums[(i+1) % n]){
                decreasing = false;
            }
        }
        if(increasing){
            result = min(result,index);
            result = min(result,n-index+2);
        }
        if(decreasing){
            result = min(result,index+2);
            result = min(result,n-index);
        }
        if(result == INT_MAX){
            return -1;
        }
        else{
            return result;
        }
    }
};©leetcode