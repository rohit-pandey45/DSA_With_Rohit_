class Solution {
  public:
    int numOfWays(int n, int m) {
        long long cells = 1LL * n * m;

        long long total = cells * (cells - 1);

        long long attacking =
            4LL * ((1LL * (n - 1) * (m - 2)) +
                   (1LL * (n - 2) * (m - 1)));

        return total - attacking;
    }
};
        // int totalCells = 1LL * n * m;
        // int totalWays = totalCells * (totalCells - 1);

        // vector<pair<int,int>> moves = {
        //     {2,1}, {2,-1}, {-2,1}, {-2,-1},
        //     {1,2}, {1,-2}, {-1,2}, {-1,-2}
        // };

        // int attacking = 0;

        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < m; j++) {
        //         for(auto &[dx, dy] : moves) {
        //             int ni = i + dx;
        //             int nj = j + dy;

        //             if(ni >= 0 && ni < n && nj >= 0 && nj < m)
        //                 attacking++;
        //         }
        //     }
        // }

        // return totalWays - attacking;
        
    
