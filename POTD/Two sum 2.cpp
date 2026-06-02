class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        unordered_map<int,int> mpp;
        for(int i = 0; i<n; i++){
            int num = numbers[i];
            int more = target - num;
            if(mpp.find(more) != mpp.end()){
                return {mpp[more],i+1};
            }
            mpp[num] = i+1;
        }
        return {};
    }
};