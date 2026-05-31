class FenwickTree {
public:
    vector<int> bit;

    FenwickTree(int n) {
        bit.resize(n + 1, 0);
    }

    void update(int idx, int val) {
        while (idx < bit.size()) {
            bit[idx] = max(bit[idx], val);
            idx += idx & -idx;
        }
    }

    int query(int idx) {
        int ans = 0;

        while (idx > 0) {
            ans = max(ans, bit[idx]);
            idx -= idx & -idx;
        }

        return ans;
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {

        int LIMIT = 50000;
        vector<bool> ans;

        set<int> obstacles = {0, LIMIT};

        // Insert all obstacles first
        for (auto &q : queries) {
            if (q[0] == 1) {
                obstacles.insert(q[1]);
            }
        }

        FenwickTree bit(LIMIT + 2);

        // Build initial gaps
        auto it = obstacles.begin();

        while (next(it) != obstacles.end()) {

            int left = *it;
            int right = *next(it);

            bit.update(right, right - left);

            ++it;
        }

        // Process queries in reverse
        for (int i = queries.size() - 1; i >= 0; --i) {

            auto &q = queries[i];

            // Type 1 -> remove obstacle
            if (q[0] == 1) {

                int x = q[1];

                auto it = obstacles.find(x);

                int left = *prev(it);
                int right = *next(it);

                // Merge gaps
                bit.update(right, right - left);

                obstacles.erase(it);
            }

            else {

                int x = q[1];
                int sz = q[2];

                auto it = obstacles.upper_bound(x);

                int prevObstacle = *prev(it);

                int bestGap = max(
                    bit.query(prevObstacle),
                    x - prevObstacle
                );

                ans.push_back(bestGap >= sz);
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};