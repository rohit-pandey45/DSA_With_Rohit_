class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<pair<int,int>> st;        //pair of element and its index position
        for(int i = 0; i<arr.size(); i++){
            //If stack is not empty and element at the top of stack is <= current element 
            //then it means that we have to keep popping from the stack till we 
            //found a larger number than the current element
            while(!st.empty() && st.top().first<=arr[i]){
                st.pop();   
            }
            //if stack is empty it means no pge is present so only that number will count
            //else ans[i] = current index - index at which pge exists
            ans[i] = st.empty()?(i+1):(i - st.top().second);
            //Pushing cureent pair to stack
            st.push({arr[i],i});
        }
        return ans;
    }
};
//  // st.pop();//
// class StockSpanner {
//     private:
//     stack<pair<int,int>> st;
//     // vector<int> ans;
//     int ind;
// public:
//     StockSpanner() {
//         ind = -1;
       
//     }
    
//     int next(int price) {
//         ind = ind + 1;
//         while(!st.empty() && st.top().first <= price){
//             st.pop();
//         }
//         int ans = ind - (st.empty()?-1:(st.top().second));
//         st.push({price,ind});
//         return ans;
//     }
//     // return ans;
// };

// /**
//  * Your StockSpanner object will be instantiated and called as such:
//  * StockSpanner* obj = new StockSpanner();
//  * int param_1 = obj->next(price);
//  */