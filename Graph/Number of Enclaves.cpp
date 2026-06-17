class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis){
        int m = grid.size();
        int n = grid[0].size();

        vis[row][col] = 1;

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        for(int i = 0; i<4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !vis[nrow][ncol] && grid[row][col] == 1){
                dfs(nrow,ncol,grid,vis);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int> (n,0));

        //Check for Boundary Rows and Columns
        //first and last columns
        for(int i = 0; i<m; i++){
            if(grid[i][0] == 1 && !vis[i][0]);
            dfs(i,0,grid,vis);

            if(grid[i][n-1] == 1 && !vis[i][n-1]){
                dfs(i,n-1,grid,vis);
            }
        }
        //first and last row
        for(int i = 0; i<n; i++){
            if(grid[0][i] == 1 && !vis[0][i]){
                dfs(0,i,grid,vis);
            }

            if(grid[m-1][i] == 1 && !vis[m-1][i]){
                dfs(m-1,i,grid,vis);
            }
        }
        int ans = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    ans++;
                }
            }
        }
        return ans;
    }
};