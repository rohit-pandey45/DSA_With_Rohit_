class Solution {
public:
    int finddays(vector<int>& weights, int capacity){
        int dayz = 1;
        int load = 0;
        for(int i = 0; i<weights.size(); i++){
            if (weights[i]+load>capacity){
                dayz += 1;
                load = weights[i];
            }
            else{
                load += weights[i];
            }
        }
        return dayz;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        while(low<=high){
            int mid = (low+high)/2;
            int noofd = finddays(weights,mid);
            if (noofd<=days){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};