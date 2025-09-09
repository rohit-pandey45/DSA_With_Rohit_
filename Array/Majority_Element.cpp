class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //BRUTE FORCE APPROACH

        // int n = nums.size();
        // for(int i = 0; i<n; i++){
        //     int ele = nums[i];
        //     int cnt = 0;
        //     for(int j = 0; j<n; j++){
        //         if(nums[j] == ele){
        //             cnt++;
        //         }
        //     }
        //     if(cnt > n/2)   return ele;
        // }
        int n = nums.size();
        int count  = 0;
        int ele = 0;
        for(int i = 0; i<n; i++){
            if(count == 0){
                count = 1;
                ele = nums[i];
            }
            else if(nums[i] == ele){
                count++;
            }
            else{
                count--;
            }
        }
        int cnt = 0;
        for(int i = 0; i<n; i++){
            if (nums[i] == ele){
                cnt++;
            }
        }
        if(cnt>n/2){
            return ele;
        }
        return -1;
    }
};