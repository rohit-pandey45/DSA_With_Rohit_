class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> nextGreater;
        
        for(int i = nums2.size() - 1; i >= 0; i--) {
            int num = nums2[i];
            while(!st.empty() && st.top() <= num) {
                st.pop();
            }

            nextGreater[num] = st.empty() ? -1 : st.top();
            st.push(num);
        }
        
        vector<int> ans;
        for(int num : nums1) {
            ans.push_back(nextGreater[num]);
        }

        return ans;
    }
};