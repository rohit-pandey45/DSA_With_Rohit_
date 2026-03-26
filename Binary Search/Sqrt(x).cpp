// class Solution {
// public:
//     int mySqrt(int x) {
//         //base Case
//         if(x<2)     return x;
//         int low = 1;
//         int high = x/2;
//         int ans = 0;
//         while(low<=high){
//             int mid = (low+high)/2;
//             if((long long) mid * mid <= x){
//                 ans = mid;
//                 low = mid + 1;
//             }
//             else{
//                 high = mid - 1;
//             }
//         }
//         return ans;
//     }
// };

class Solution {
  public:
    int floorSqrt(int n) {
        int low = 0;
        int high = n;
        while(low <= high){
            int mid = low + ((high - low)/2);
            if((mid*mid) == n){
                return mid;
            }
            else if((mid*mid)>n){
                high = mid - 1;
            }
            else{
                low = mid+1;
            }
        }
        return high;
        
    }
};