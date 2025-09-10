class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        //Given equal number of positive and negative integers
        // int n = nums.size();
        // int pos_index = 0;
        // int neg_index = 1;
        // vector<int> result(n,0);
        // for (int i = 0; i<n; i++){
        //     if (nums[i]<0){
        //         result[neg_index] = nums[i];
        //         neg_index += 2;
        //     }
        //     else{
        //         result[pos_index] = nums[i];
        //         pos_index += 2;
        //     }
        // }
        // return result;
        int n = nums.size();
        vector<int> pos(n/2);
        vector<int> neg(n/2);
        int j = 0, k = 0;
        for(int i = 0; i<n; i++){
            if(nums[i]>0){
                pos[j] = nums[i];
                j++;
            }
            else if(nums[i]<0){
                neg[k] = nums[i];
                k++;
            }
        }
        int a = 0, b = 0;
        for(int i = 0; i<n; i+=2){
            nums[i] = pos[a];
            a++;
            nums[i+1] = neg[b];
            b++;
        }
        return nums;
    }
};