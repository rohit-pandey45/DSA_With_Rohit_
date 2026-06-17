class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {

        int n = isWater.size();
        int m = isWater[0].size();

        vector<vector<int>> ans(n, vector<int>(m, -1));
        queue<pair<int,int>> q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(isWater[i][j] == 1) {
                    ans[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        while(!q.empty()) {
            auto [row,col] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++) {
                int nrow = row + drow[k];
                int ncol = col + dcol[k];

                if(nrow >= 0 && nrow < n &&
                   ncol >= 0 && ncol < m &&
                   ans[nrow][ncol] == -1) {

                    ans[nrow][ncol] = ans[row][col] + 1;
                    q.push({nrow,ncol});
                }
            }
        }

        return ans;
    }
};