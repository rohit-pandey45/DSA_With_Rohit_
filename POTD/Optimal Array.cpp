class Solution {
public:
    vector<int> optimalArray(vector<int> &arr) {
        int n = arr.size();

        vector<long long> prefix(n + 1, 0);
        for(int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + arr[i];
        }

        vector<int> ans;

        for(int i = 0; i < n; i++) {
            int mid = i / 2;

            long long leftCost =
                1LL * arr[mid] * (mid + 1) - prefix[mid + 1];

            long long rightCost =
                (prefix[i + 1] - prefix[mid + 1])
                - 1LL * arr[mid] * (i - mid);

            ans.push_back((int)(leftCost + rightCost));
        }

        return ans;
    }
};