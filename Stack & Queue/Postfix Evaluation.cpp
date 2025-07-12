class Solution {
  public:
    int evaluate(vector<string>& arr) {
        //We Will store the elements in a Stack
        stack<int> st;
        //Iterating Through each char in the arr
        for(string& str : arr){
            if(str == "+" || str == "-" || str == "*" || str == "/"){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                if(str == "+")  st.push(a+b);
                else if(str == "-")  st.push(a-b);
                else if(str == "*")  st.push(a*b);
                else if(str == "/")  st.push(a/b);
            }
            else{
                st.push(stoi(str));
            }
        }
        return st.top();
    }
};