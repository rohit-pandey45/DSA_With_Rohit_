//Sort a/t Profit
//hash arr initialised with -1 with size of max nof of days 
//we will try to perform the job on its last deadline date
class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        vector<int> ans = {0,0};
        vector<pair<int,int>> jobs;
        for(int i = 0; i<n; i++){
            jobs.push_back({profit[i],deadline[i]});
        }
        sort(jobs.begin(),jobs.end(),greater<pair<int,int>>());
        int maxdeadline = 0;
        for(auto& job : jobs){
            maxdeadline = max(maxdeadline,job.second);
        }
        vector<int> slot(maxdeadline+1, -1);
        int countjobs = 0;
        int totalprofit = 0;
        for(auto& job : jobs){
            int pro_fit = job.first;
            int dead_line = job.second;
            for(int i = dead_line; i>0; i--){
                if(slot[i] == -1){
                    slot[i] = pro_fit;
                    countjobs++;
                    totalprofit += pro_fit;
                    break;
                }
            }
        }
        return {countjobs,totalprofit};
    }
};