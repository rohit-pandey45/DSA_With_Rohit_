class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // vector<int> brr;
        // int n = nums.size();
        // for (int i = 0; i<n; i++){
        //     if (nums[i] != 0){
        //         brr.push_back(nums[i]);
        //     }
        // }
        // for (int j = brr.size(); j<n; j++){
        //     brr.push_back(0);
        // }
        // for (int i = 0; i<n; i++){
        //     nums[i] = brr[i];
        // }
        int n = nums.size();
        int j = 0;
        for(int i = 0; i<n; i++){
            if(nums[i] == 0){
                continue;
            }
            else{
                swap(nums[i],nums[j]);
                j++;
            }
        }
    }
    
};