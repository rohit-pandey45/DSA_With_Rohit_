class Solution {
public:
    const int LIMIT = 19900;
    const int GRID = 1000000;

    bool bfs(vector<int>& start, vector<int>& finish,
             unordered_set<long long>& blocked) {

        queue<pair<int,int>> q;
        unordered_set<long long> vis;

        auto encode = [&](long long x, long long y) {
            return (x << 20) | y;
        };

        q.push({start[0], start[1]});
        vis.insert(encode(start[0], start[1]));

        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        while (!q.empty() && vis.size() <= LIMIT) {
            auto [x, y] = q.front();
            q.pop();

            if (x == finish[0] && y == finish[1])
                return true;

            for (int k = 0; k < 4; k++) {
                long long nx = x + dx[k];
                long long ny = y + dy[k];

                if (nx < 0 || ny < 0 ||
                    nx >= GRID || ny >= GRID)
                    continue;

                long long key = encode(nx, ny);

                if (blocked.count(key) || vis.count(key))
                    continue;

                vis.insert(key);
                q.push({(int)nx, (int)ny});
            }
        }

        return vis.size() > LIMIT;
    }

    bool isEscapePossible(vector<vector<int>>& blocked,
                          vector<int>& source,
                          vector<int>& target) {

        unordered_set<long long> blockSet;

        auto encode = [&](long long x, long long y) {
            return (x << 20) | y;
        };

        for (auto& b : blocked)
            blockSet.insert(encode(b[0], b[1]));

        return bfs(source, target, blockSet) &&
               bfs(target, source, blockSet);
    }
};