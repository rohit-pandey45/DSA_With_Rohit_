class Solution {
public:
    // Minimum time to reach bottom right cell
    int swimInWater(vector<vector<int>>& grid) {
        // Get grid size
        int n = grid.size();

        // Create a min-heap for cells based on elevation
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;

        // Create visited matrix
        vector<vector<int>> visited(n, vector<int>(n, 0));

        // Push starting cell to heap
        minHeap.push({grid[0][0], 0, 0});
        visited[0][0] = 1;

        // Direction vectors for movement
        vector<pair<int, int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        // Process heap until destination is reached
        while (!minHeap.empty()) {
            // Extract cell with least elevation
            auto curr = minHeap.top(); minHeap.pop();
            int elevation = curr[0], r = curr[1], c = curr[2];

            // If destination reached, return elevation
            if (r == n - 1 && c == n - 1) return elevation;

            // Explore neighboring cells
            for (auto& dir : dirs) {
                int nr = r + dir.first;
                int nc = c + dir.second;

                // Check bounds and if not visited
                if (nr >= 0 && nc >= 0 && nr < n && nc < n && !visited[nr][nc]) {
                    visited[nr][nc] = 1;
                    minHeap.push({max(elevation, grid[nr][nc]), nr, nc});
                }
            }
        }
        return -1;
    }
};