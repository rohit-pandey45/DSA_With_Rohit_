// class Solution {
// public:
//     int minimumDifference(vector<int>& nums) {
//         int n = nums.size();
//         int totalsum = 0;
//         for(int i = 0; i<n; i++){
//             totalsum += nums[i];
//         }

//         vector<vector<bool>> dp(n, vector<bool> (totalsum+1,0));
//         for(int i = 0; i<n; i++)    dp[i][0] = true;
//         if(nums[0] <= totalsum)    dp[0][nums[0]] = true;

//         for(int ind = 1; ind<n; ind++){
//             for(int target = 1; target<=totalsum; target++){
//                 bool nottake = dp[ind-1][target];
//                 bool take = false;
//                 if(nums[ind] <= target){
//                     take = dp[ind-1][target-nums[ind]];
//                 }
//                 dp[ind][target] = take | nottake;
//             }
//         }

//         int mini = 1e9;
//         for(int s1 = 0; s1<=totalsum/2; s1++){
//             if(dp[n-1][s1] == true){
//                 mini = min(mini,abs((totalsum - s1) - s1));
//             }
//         }
//         return mini;
//     }
// };
class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int totalsum = 0;
        for(int x : nums) totalsum += x;

        int half = n / 2;

        vector<int> left(nums.begin(), nums.begin() + half);
        vector<int> right(nums.begin() + half, nums.end());

        vector<vector<int>> lsum(half + 1), rsum(half + 1);

        // Left subset sums
        for(int mask = 0; mask < (1 << half); mask++) {
            int sum = 0, cnt = 0;
            for(int i = 0; i < half; i++) {
                if(mask & (1 << i)) {
                    sum += left[i];
                    cnt++;
                }
            }
            lsum[cnt].push_back(sum);
        }

        // Right subset sums
        int rsize = n - half;
        for(int mask = 0; mask < (1 << rsize); mask++) {
            int sum = 0, cnt = 0;
            for(int i = 0; i < rsize; i++) {
                if(mask & (1 << i)) {
                    sum += right[i];
                    cnt++;
                }
            }
            rsum[cnt].push_back(sum);
        }

        int mini = 1e9;

        for(int i = 0; i <= half; i++) {
            sort(rsum[half - i].begin(), rsum[half - i].end());

            for(int s1 : lsum[i]) {
                int target = totalsum / 2 - s1;
                auto &vec = rsum[half - i];

                auto it = lower_bound(vec.begin(), vec.end(), target);

                if(it != vec.end())
                    mini = min(mini, abs(totalsum - 2 * (s1 + *it)));

                if(it != vec.begin())
                    mini = min(mini, abs(totalsum - 2 * (s1 + *prev(it))));
            }
        }

        return mini;
    }
};
