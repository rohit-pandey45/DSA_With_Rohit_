class Solution {
	public:
	  int solve(vector<int>& arr, int l, int r, int lr, int rl) {
        if (l > r) return 0;

        int m = (l + r) / 2;
        int ans = 0;

        // arr[m] is binary searchable
        if (lr < arr[m] && arr[m] < rl)
            ans = 1;

        ans += solve(arr, l, m - 1, lr, min(rl, arr[m]));
        ans += solve(arr, m + 1, r, max(lr, arr[m]), rl);

        return ans;
    }
	int binarySearchable(vector<int>& arr) {
		return solve(arr, 0, arr.size() - 1, INT_MIN, INT_MAX);
		// int n = arr.size();
		// int cnt = 0;
		// for(int i = 0; i<n; i++){
		//     int l = 0;
		//     int r = n-1;
		
		//     while(l <= r){
		//         int mid = l + (r - l)/2;
		//         if(arr[mid] == arr[i]){
		//             cnt++;
		//         }
		//         else if(arr[mid] < arr[i]){
		//             l = mid + 1;
		//         }
		//         else{
		//             r = mid - 1;
		//         }
		//     }
		// }
		// return cnt;
	}
};
