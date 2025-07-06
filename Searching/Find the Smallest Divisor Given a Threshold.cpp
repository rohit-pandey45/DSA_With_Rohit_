class Solution {
public:
    int sumofD(vector<int>& nums, int threshold){
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum += ceil((double)(nums[i]) / (double)(threshold));
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        if (nums.size()>threshold) return -1;
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        int ans = INT_MAX;
        while(low<=high){
            int mid = (low+high)/2;
            if (sumofD(nums,mid)<= threshold){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};