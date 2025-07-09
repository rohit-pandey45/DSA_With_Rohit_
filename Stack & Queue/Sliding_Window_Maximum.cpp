class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        //Since we have to keep track of the window elements i.e. we have to perform operations
        //from both the front and back side
        //Therefore we will use a Double Ended Queue
        deque<int> dq;
        vector<int> ans;
        for(int i = 0; i<n; i++){
            //Maintaining Window Size
            while(!dq.empty() && dq.front() <= i-k){
                dq.pop_front();
            }
            //Maintaining elements in monotonic decreasing order
            while(!dq.empty() && nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            //Store The index posn of the Current element
            dq.push_back(i);
            //
            if(i>=k-1){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};