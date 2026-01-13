// class Solution {
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int sum = accumulate(nums.begin(), nums.end(), 0);
//         if (sum - target < 0 || (sum - target) % 2) return 0;

//         int s2 = (sum - target) / 2;
//         int n = nums.size();

//         vector<vector<int>> dp(n, vector<int>(s2 + 1, 0));

//         if (nums[0] == 0) dp[0][0] = 2;
//         else dp[0][0] = 1;

//         if (nums[0] != 0 && nums[0] <= s2)
//             dp[0][nums[0]] = 1;

//         for (int i = 1; i < n; i++) {
//             for (int j = 0; j <= s2; j++) {
//                 int notTake = dp[i - 1][j];
//                 int take = 0;
//                 if (nums[i] <= j)
//                     take = dp[i - 1][j - nums[i]];
//                 dp[i][j] = take + notTake;
//             }
//         }

//         return dp[n - 1][s2];
//     }
// };
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum - target < 0 || (sum - target) % 2) return 0;

        int s2 = (sum - target) / 2;
        vector<int> dp(s2 + 1, 0);

        dp[0] = 1;

        for (int num : nums) {
            for (int j = s2; j >= num; j--) {
                dp[j] += dp[j - num];
            }
        }

        return dp[s2];
    }
};
