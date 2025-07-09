
class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n+1, INT_MIN);
        vector<int> pse_ind(n);
        vector<int> nse_ind(n);
        stack<int> st;
        //Finding Previous Smaller Index for Each Element
        for(int i = 0; i<n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            pse_ind[i] = st.empty()?-1:st.top();
            st.push(i);
        }
        //Clearing Stack For Finding nse_ind
        while(!st.empty())  st.pop();
        //Finding Next Smaller Index for Each Element
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            nse_ind[i] = st.empty()?n:st.top();
            st.push(i);
        }
        //Creating Window size from i to arr.size()
        for(int i = 0; i<n; i++){
            int len = nse_ind[i] - pse_ind[i] - 1;      //Computing minimum in current window size
            ans[len] = max(ans[len],arr[i]);
        }
        for(int i = n-1; i>=1; i--){
            ans[i] = max(ans[i],ans[i+1]);
        }
        ans.erase(ans.begin());
        return ans;
    }
};