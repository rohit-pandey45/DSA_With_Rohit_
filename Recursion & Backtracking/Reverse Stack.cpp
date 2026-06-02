class Solution {
  public:
    void insertAtBottom(stack<int> &st, int topVal){
        if(st.empty()){
            st.push(topVal);
            return;
        }
        int val = st.top();
        st.pop();
        insertAtBottom(st, topVal);
        st.push(val);
    }
    void reverseStack(stack<int> &st) {
        if(st.empty()){
            return;
        }
        int topVal = st.top();
        st.pop();
        reverseStack(st);
        insertAtBottom(st,topVal);
        
    }
};