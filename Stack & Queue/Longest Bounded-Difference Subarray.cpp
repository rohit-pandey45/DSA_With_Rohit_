class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        int n = arr.size();
        vector<int> ans;
        deque<int> maxi;
        deque<int> mini;
        int start = 0, end = 0;
        int ans_start = 0, ans_end = 0;
        while(end<n){
            while(!maxi.empty() && arr[maxi.back()]<arr[end]){
                maxi.pop_back();
            }
            while(!mini.empty() && arr[mini.back()]>arr[end]){
                mini.pop_back();
            }
            maxi.push_back(end);
            mini.push_back(end);
            while(arr[maxi.front()] - arr[mini.front()] > x){
                if(start == mini.front()){
                    mini.pop_front();
                }
                if(start == maxi.front()){
                    maxi.pop_front();
                }
                start += 1;
            }
            if(end - start > ans_end - ans_start){
                ans_start = start;
                ans_end = end;
            }
            end += 1;
        }
        for(int i = ans_start; i<=ans_end; i++){
            ans.push_back(arr[i]);
        }
        return ans;
    }
};