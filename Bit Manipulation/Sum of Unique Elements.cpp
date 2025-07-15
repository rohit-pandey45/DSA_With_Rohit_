class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        unordered_map<int,int> mpp;
        for(int i = 0; i<n; i++){
            mpp[nums[i]]++;
        }
        for(int i = 0; i<n; i++){
            if(mpp[nums[i]] == 1){
                sum = sum + nums[i];
            }
        }
        return sum;
    }
};