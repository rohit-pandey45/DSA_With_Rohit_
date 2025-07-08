class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;
        for(int i = 0; i<n; i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int element  = st.top(); //Stores the index Position of the Element in actual
                st.pop();   //We have found the element so now pop it from the stack
                int nse = i;        //Storing index at which nse is present
                int pse = st.empty()?-1:st.top();      //Storing the index at which pse is present
                int area = heights[element]*(nse - pse - 1);        //Calculating Area
                maxArea = max(maxArea,area);        //Storing the maximum area
            }
            st.push(i);     //Pushing the index posn of the current element to stack
        }
        while(!st.empty()){
            int element = st.top();         
            st.pop();
            int nse = n;        //In this sitn there will be no nse. Hypothetically it will be n
            int pse = st.empty()?-1:st.top();
            int area = heights[element]*(nse - pse - 1);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;       //Edge Case
        int n = matrix.size();
        int m = matrix[0].size();
        int maxArea = 0;
        vector<vector<int>> prefsum(n, vector<int>(m, 0));
        for(int j = 0; j<m; j++){
            // int sum = 0;
            for(int i = 0; i<n; i++){
                // sum += matrix[i][j];
                // if(matrix[i][j] == 0)   sum = 0;
                // prefsum[i][j] = sum;
                if (matrix[i][j] == '1') {
                    prefsum[i][j] = (i == 0) ? 1 : prefsum[i - 1][j] + 1;
                } else {
                    prefsum[i][j] = 0;
                }
            }
        }
        for(int i = 0; i<n; i++){
            maxArea = max(maxArea,largestRectangleArea(prefsum[i]));
        }
        return maxArea;
    }
};