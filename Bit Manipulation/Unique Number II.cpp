class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {
        int n = arr.size();
        int xorall = 0;
        for(int i = 0; i<n; i++){
            xorall = xorall ^ arr[i];
        }
        int xordiff = xorall & -xorall;
        int a = 0, b = 0;
        for(int i = 0; i<n; i++){
            if(arr[i] & xordiff){
                a ^= arr[i];
            }
            else{
                b ^= arr[i];
            }
        }
        return {min(a,b),max(a,b)};
    }
};