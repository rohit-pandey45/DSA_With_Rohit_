class Solution {
public:
    int fungoal(vector<int>& nums, int k){
        int n = nums.size();
        int l = 0;
        int r = 0;
        int sum = 0;
        int cnt = 0;
        if(k < 0)    return 0;
        while(r < n){
            sum += nums[r];
            while(sum > k){
                sum = sum - nums[l];
                l++;
            }
            cnt = cnt + (r-l+1);
            r = r + 1;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        //BRUTE FORCE APPROACH
        //int n = nums.size();
        // int count = 0;
        // for(int i = 0; i<n; i++){
        //     int sum = 0;
        //     for(int j = i; j<n; j++){
        //         sum += nums[j];
        //         if(sum == goal) count++;
        //     }
        // }
        // return count;

        //OPTIMAL APPROACH
        // int n = nums.size();
        // int count = 0;
        // unordered_map<int,int> mpp;
        // mpp[0] = 1;
        // int prefsum = 0;
        // for(int i = 0; i<n; i++){
        //     prefsum += nums[i];
        //     int more = prefsum - goal;
        //     if(mpp.find(more) != mpp.end()){
        //         count = count + mpp[more];
        //     }
        //     mpp[prefsum]++;
        // }
        // return count;
        // int n = nums.size();
        // int l = 0;
        // int r = 0;
        // int sum = 0;
        // int cnt = 0;
        // while(r < n){
        //     sum += nums[r];
        //     while(sum > goal){
        //         sum = sum - nums[l];
        //         l++;
        //     }
        //     cnt = cnt + (r-l+1);
        //     r = r + 1;
        // }
        // return cnt;
        return fungoal(nums, goal) 
             - fungoal(nums, goal - 1);
    }
    
};