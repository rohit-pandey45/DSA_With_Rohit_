
class Solution {
  public:
    bool isBalanced(string& k) {
        stack<int> st;
        int n = k.size();
        for(int i = 0; i<n; i++){
            if(k[i] == '('  || k[i] == '[' || k[i] == '{'){
                st.push(k[i]);
            }
            else{
                if(st.empty())  return false;
                char ch = st.top();
                if(k[i] == ')' && ch == '(' || k[i] == ']' && ch == '[' || k[i] == '}' && ch == '{'){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        return st.empty();
    }
};