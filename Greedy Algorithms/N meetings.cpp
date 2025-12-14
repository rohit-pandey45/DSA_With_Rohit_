class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();
        vector<pair<int,int>> meet;
        for(int i = 0; i<n; i++){
            meet.push_back({end[i],start[i]});
        }
        sort(meet.begin(),meet.end());
        int cnt = 1;    //coz first meeting will always occur after sorting
        int freetime = meet[0].first;
        for(int i = 0; i<n; i++){
            if(meet[i].second > freetime){
                cnt++;
                freetime = meet[i].first;
            }
        }
        return cnt;
    }
};