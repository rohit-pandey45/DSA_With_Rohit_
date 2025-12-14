class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int m = intervals[0].size();
        if(n == 0)  return 0;
        // sort by end time
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });
        int cnt = 1;    //coz first meeting will always occur after sorting
        int freetime = intervals[0][1];
        for(int i = 1; i<n; i++){
            if(intervals[i][0] >= freetime){
                cnt++;
                freetime = intervals[i][1];
            }
        }
        return n - cnt;
    }
};