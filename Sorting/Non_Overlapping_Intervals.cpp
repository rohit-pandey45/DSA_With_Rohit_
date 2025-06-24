class Solution {
  public:
  static bool comp(vector<int> &a, vector<int> &b){
      return a[1]<b[1];
  }
    int minRemoval(vector<vector<int>> &intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int last = intervals[0][1];
        int count = 0;
        for (int i = 1; i<intervals.size(); i++){
            if (intervals[i][0] < last){
                count++;
            }
            else{
                last = intervals[i][1];
            }
        }
        return count;
        
    }
};
