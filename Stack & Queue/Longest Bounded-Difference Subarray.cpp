class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        int n = arr.size();
        // vector<int> ans;
        //For Maintaining the Max no in a Monotonic Order
        deque<int> maxdeque;
        //For Maintaining the Max no in a Monotonic Order
        deque<int> mindeque;
        int left = 0;
        int maxlen = 0;
        int startind = 0;
        for(int right = 0; right<n; right++){
            //Maintaining Max Deque
            while(!maxdeque.empty() && maxdeque.back() <= arr[right]){
                maxdeque.pop_back();
            }
            maxdeque.push_back(arr[right]);
            //Maintaining Min Deque
            while(!mindeque.empty() && mindeque.back() >= arr[right]){
                mindeque.pop_back();
            }
            mindeque.push_back(arr[right]);
            //Shrinking Window
            while(!maxdeque.empty() && !mindeque.empty() && (maxdeque.front() - mindeque.front() > x)){
                if(arr[left] == maxdeque.front())   maxdeque.pop_front();
                if(arr[left] == mindeque.front())   mindeque.pop_front();
                left++;
            }
            if(right - left + 1 >maxlen){
                maxlen = right - left + 1;
                startind = left;
            }
        }
        return vector<int>(arr.begin() + startind,arr.begin() + startind + maxlen);
    }
};