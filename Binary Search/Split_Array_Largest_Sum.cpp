class Solution {
private:
    int splitArr(vector<int>& nums, int k, int mid){
        int n = nums.size();
        int count = 1;
        int minSum = 0;
        for(int i = 0; i<n; i++){
            if(minSum + nums[i] <= mid){
                minSum += nums[i];
            }
            else{
                count++;
                minSum = nums[i];
            }
        }
        return count;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        //Initialising Search Space
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);

        //Applying Binary Search
        while(low <= high){
            int mid = low + ((high - low)/2);
            int ans = splitArr(nums,k,mid);
            if(ans > k){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return low;
    }
};