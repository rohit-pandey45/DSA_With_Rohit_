class Solution {
  public:
    vector<int> freqInRange(vector<int>& arr, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> pos;

        // Step 1: store indices of each element
        for (int i = 0; i < arr.size(); i++) {
            pos[arr[i]].push_back(i);
        }

        vector<int> ans;

        // Step 2: answer queries using binary search
        for (auto &q : queries) {
            int l = q[0], r = q[1], x = q[2];

            if (pos.find(x) == pos.end()) {
                ans.push_back(0);
                continue;
            }

            vector<int> &v = pos[x];

            int left = lower_bound(v.begin(), v.end(), l) - v.begin();
            int right = upper_bound(v.begin(), v.end(), r) - v.begin();

            ans.push_back(right - left);
        }

        return ans;
    }
};
// class Solution {
//   public:
//     vector<int> freqInRange(vector<int>& arr, vector<vector<int>>& queries) {
//         int n = arr.size();
//         vector<int> ans;
//         for(auto& q : queries){
//             int l = q[0];
//             int r = q[1];
//             int x = q[2];
//             int cnt = 0;
//             for(int i = l; i<=r; i++){
//                 if(arr[i] == x){
//                     cnt++;
//                 }
//             }
//             ans.push_back(cnt);
//         }
//         return ans;
//     }
// };