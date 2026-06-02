// class Solution {
// public:
    // long long solveDirection(vector<int>& firstStart,
    //                          vector<int>& firstDur,
    //                          vector<int>& secondStart,
    //                          vector<int>& secondDur) {
        
    //     int m = secondStart.size();

    //     vector<pair<long long,long long>> rides;
    //     for (int i = 0; i < m; i++) {
    //         rides.push_back({secondStart[i], secondDur[i]});
    //     }

    //     sort(rides.begin(), rides.end());

    //     vector<long long> starts(m);
    //     vector<long long> prefMinDur(m);
    //     vector<long long> suffMinFinish(m);

    //     for (int i = 0; i < m; i++) {
    //         starts[i] = rides[i].first;

    //         if (i == 0)
    //             prefMinDur[i] = rides[i].second;
    //         else
    //             prefMinDur[i] = min(prefMinDur[i - 1], rides[i].second);
    //     }

    //     for (int i = m - 1; i >= 0; i--) {
    //         long long val = rides[i].first + rides[i].second;

    //         if (i == m - 1)
    //             suffMinFinish[i] = val;
    //         else
    //             suffMinFinish[i] = min(suffMinFinish[i + 1], val);
    //     }

    //     long long ans = LLONG_MAX;

    //     for (int i = 0; i < (int)firstStart.size(); i++) {
    //         long long x = (long long)firstStart[i] + firstDur[i];

    //         int pos = upper_bound(starts.begin(), starts.end(), x) - starts.begin();

    //         long long best = LLONG_MAX;

    //         if (pos > 0) {
    //             best = min(best, x + prefMinDur[pos - 1]);
    //         }

    //         if (pos < m) {
    //             best = min(best, suffMinFinish[pos]);
    //         }

    //         ans = min(ans, best);
    //     }

    //     return ans;
    // }

//     int earliestFinishTime(vector<int>& landStartTime,
//                            vector<int>& landDuration,
//                            vector<int>& waterStartTime,
//                            vector<int>& waterDuration) {

//         // long long landFirst =
//         //     solveDirection(landStartTime, landDuration,
//         //                    waterStartTime, waterDuration);

//         // long long waterFirst =
//         //     solveDirection(waterStartTime, waterDuration,
//         //                    landStartTime, landDuration);

//         // return (int)min(landFirst, waterFirst);
//         int n = landStartTime.size();
//         int m = waterStartTime.size();
//         int ans = INT_MAX;
//         for(int i = 0; i<n; i++){
//             for(int j = 0; j<m; j++){
//                 int land = landStartTime[i] + landDuration[i];
//                 int land_water = max(land, waterStartTime[j]) + waterDuration[j];
//                 ans = min(ans,land_water);

//                 int water = waterStartTime[j] + waterDuration[j];
//                 int water_land = max(water, landStartTime[i]) + landDuration[i];
//                 ans = min(ans,water_land);
//             }
//         }
//         return ans;
//     }
// };

class Solution {
    int solve(vector<int>& start1, vector<int>& duration1, vector<int>& start2,
              vector<int>& duration2) {
        int finish1 = INT_MAX;
        for (int i = 0; i < start1.size(); i++) {
            finish1 = min(finish1, start1[i] + duration1[i]);
        }

        int finish2 = INT_MAX;
        for (int i = 0; i < start2.size(); i++) {
            finish2 = min(finish2, max(start2[i], finish1) + duration2[i]);
        }
        return finish2;
    }

public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        int land_water =
            solve(landStartTime, landDuration, waterStartTime, waterDuration);
        int water_land =
            solve(waterStartTime, waterDuration, landStartTime, landDuration);
        return min(land_water, water_land);
    }
};