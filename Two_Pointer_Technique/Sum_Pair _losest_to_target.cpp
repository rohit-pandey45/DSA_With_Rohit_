// User function template for C++
class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        vector<int> ans;
        int n = arr.size();
        if (n == 1) return ans;     //Edge Case
        sort(arr.begin(),arr.end());            //TC :O(nlogn)
        int diff = INT_MAX;
        int low = 0;
        int high = n-1;
        while(low<high){
            int sum = arr[low] + arr[high];
            //Sum closest to target
            if((abs(target-sum))<diff){
                diff = abs(target - sum);
                ans = {arr[low],arr[high]};
            }
            if (sum<target){
                low++;
            }
            else if(sum>target){
                high--;
            }
            //Sum = Traget
            else{
                return ans;
            }
        }
        return ans;
        
    }
};