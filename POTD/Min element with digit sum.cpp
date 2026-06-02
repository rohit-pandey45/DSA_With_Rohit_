class Solution {
public:
    int minElement(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i<n; i++){
            int ele = nums[i];
            int sum = 0;
            while(ele > 0){
                int ld = ele % 10;
                sum += ld;
                ele = ele / 10;
            }
            nums[i] = sum;
        }
        int minele = INT_MAX;
        for(int i = 0; i<n; i++){
            minele = min(minele,nums[i]);
        }
        return minele;
    }
};