class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {

        vector<int> left(26, INT_MAX);
        vector<int> right(26, -1);

        int n = s.size();

        for(int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            left[c] = min(left[c], i);
            right[c] = i;
        }

        auto getInterval = [&](int start) -> pair<int,int> {

            int R = right[s[start] - 'a'];

            for(int i = start; i <= R; i++) {

                int c = s[i] - 'a';

                if(left[c] < start)
                    return {-1, -1};

                R = max(R, right[c]);
            }

            return {start, R};
        };

        vector<pair<int,int>> intervals;

        for(int c = 0; c < 26; c++) {

            if(left[c] == INT_MAX)
                continue;

            auto p = getInterval(left[c]);

            if(p.first != -1)
                intervals.push_back(p);
        }

        sort(intervals.begin(), intervals.end(),
             [](auto &a, auto &b) {
                 return a.second < b.second;
             });

        vector<string> ans;

        int lastEnd = -1;

        for(auto &[L, R] : intervals) {

            if(L > lastEnd) {
                ans.push_back(s.substr(L, R - L + 1));
                lastEnd = R;
            }
        }

        return ans;
    }
};