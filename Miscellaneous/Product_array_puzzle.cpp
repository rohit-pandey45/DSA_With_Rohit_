// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n);
        int zeroCount = 0;
        int prod = 1;
        for(int i = 0; i<n; i++){
            if(arr[i] == 0){
                zeroCount++;
            }
            else{
                prod = prod * arr[i];
            }
            
        }
        for(int i = 0; i<n; i++){
            if(zeroCount>1){
               res[i] = 0; 
            }
            else if (zeroCount == 1){
                res[i] = (arr[i] == 0)?prod:0;
            }
            else{
                res[i] = prod/arr[i];
            }
        }
        return res;
        
    }
};
