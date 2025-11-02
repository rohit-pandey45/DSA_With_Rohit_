class Solution {
public:
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
        int n = nums.size();
        int count = 0;
        unordered_map<int,int> mpp;
        mpp[0] = 1;
        int prefsum = 0;
        for(int i = 0; i<n; i++){
            prefsum += nums[i];
            int more = prefsum - goal;
            if(mpp.find(more) != mpp.end()){
                count = count + mpp[more];
            }
            mpp[prefsum]++;
        }
        return count;
    }
    
};