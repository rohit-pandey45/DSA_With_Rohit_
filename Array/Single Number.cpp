class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // int n = nums.size();
        // for (int i = 0; i<n; i++){
        //     int num = nums[i];
        //     int count = 0;
        //     for (int j = 0; j<n; j++){
        //         if (nums[j] == num){
        //             count++;
        //         }
        //     }
        //     if (count == 1) return num;
        // }
        // return 0;
        int n = nums.size();
        int xor1 = 0;
        for(int i = 0; i<n; i++){
            xor1 = xor1^nums[i];
        }
        return xor1;
    }
};