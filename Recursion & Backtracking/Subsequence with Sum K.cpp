class Solution {
public:

    vector<vector<int>> dp;

    bool func(int index, vector<int>& arr, int target){

        if(target == 0)
            return true;

        if(index == arr.size())
            return false;

        if(dp[index][target] != -1)
            return dp[index][target];

        bool take = false;

        if(arr[index] <= target)
            take = func(index + 1,
                        arr,
                        target - arr[index]);

        bool notTake = func(index + 1,
                            arr,
                            target);

        return dp[index][target] = take || notTake;
    }

    bool checkSubsequenceSum(vector<int>& arr, int k) {

        int n = arr.size();

        dp.assign(n, vector<int>(k + 1, -1));

        return func(0, arr, k);
    }
};
// class Solution {
// public:
//     bool func(int index, vector<int>& arr, int target){

//         if(index == arr.size()){
//             return target == 0;
//         }

//         // Take current element
//         bool take = func(index + 1, arr,
//                          target - arr[index]);

//         // Not take current element
//         bool notTake = func(index + 1, arr,
//                             target);

//         return take || notTake;
//     }

//     bool checkSubsequenceSum(vector<int>& arr, int k) {
//         return func(0, arr, k);
//     }
// };