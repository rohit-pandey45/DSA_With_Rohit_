class Solution {
  private :
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid){
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        queue<pair<int,int>> q;
        q.push({row,col});
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            //Traversing the Neighbours
            for(int delrow = -1; delrow<=1; delrow++){
                for(int delcol = -1; delcol<=1; delcol++){
                    int nrow = row + delrow;
                    int ncol = col + delcol;
                    if(nrow>=0 && nrow<n && ncol >= 0 && ncol<m && grid[nrow][ncol] == 'L' && !vis[nrow][ncol]){
                        vis[nrow][ncol] = 1;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
    }
  public:
    int countIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        //Create a Visited Array
        vector<vector<int>> vis(n, vector<int>(m,0));
        int cnt = 0;
        for(int row = 0; row<n; row++){
            for(int col = 0; col<m; col++){
                if(!vis[row][col] && grid[row][col] == 'L'){
                    cnt++;
                    dfs(row,col,vis,grid);
                }
            }
        }
        return cnt;
    }
};

class Solution {
public:

    void solve(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis) {
        int m = grid.size();
        int n = grid[0].size();

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                vis[nrow][ncol] = 1;
                solve(nrow, ncol, grid, vis);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        int cnt = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == '1' && !vis[i][j]) {

                    cnt++;
                    vis[i][j] = 1;

                    solve(i, j, grid, vis);
                }
            }
        }

        return cnt;
    }
};