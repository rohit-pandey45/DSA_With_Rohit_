class Solution {
public:
    string triangleType(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i = nums[0];
        int j = nums[1];
        int k = nums[2];
        if(i+j>k){
            if(i == j && j == k){
            return "equilateral";
            }
            else if (i == j || j==k || i == k){
                return "isosceles";
            }
            else {
                return "scalene";
            }
        }
        return "none";
    }
};