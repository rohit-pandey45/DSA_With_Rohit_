
class Solution {
  public:
    int maxLength(string& s) {
        int n = s.size();
        stack<int> st;
        int maxlen = 0;
        st.push(-1);
        for(int i = 0; i<n; i++){
            if(s[i] == '('){
                st.push(i);
            }
            else{
                st.pop();
                if(!st.empty()){
                    maxlen = max(maxlen, i-st.top());
                }
                else{
                    st.push(i);
                }
            }
        }
        return maxlen;
    }
};