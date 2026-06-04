class Solution {
public:
    int n;
    vector<pair<int,int>> moves = {
        {2,1}, {2,-1}, {-2,1}, {-2,-1},
        {1,2}, {1,-2}, {-1,2}, {-1,-2}
    };
    bool dfs(int x, int y, int move, vector<vector<int>>& grid){
        if(move == (n*n)-1)   return true;
        for(auto &[dx,dy] : moves){
            int nx = x + dx;
            int ny = y + dy;
            if(nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == move+1){
                return dfs(nx,ny,move+1,grid);
            }
        }
        return false;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        n = grid.size();
        if(grid[0][0] != 0) return false;
        return dfs(0,0,0,grid);
    }
};