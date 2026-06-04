class Solution {
  public:
    vector<string> ans;
    int n;
    
    void dfs(int i, int j, vector<vector<int>>& maze, vector<vector<int>>& visited, string path){
        //Base Case
        if(i == n-1 && j == n-1){
            ans.push_back(path);
            return;
        }
        visited[i][j] = 1;
        
        //Down
        if(i+1 < n && maze[i+1][j] == 1 && !visited[i+1][j]){
            dfs(i+1,j,maze,visited,path+'D');
        }
        //Left
        if(j-1 >= 0 && maze[i][j-1] == 1 && !visited[i][j-1]){
            dfs(i,j-1,maze,visited,path+'L');
        }
        //Right
        if(j+1 < n && maze[i][j+1] == 1 && !visited[i][j+1]){
            dfs(i,j+1,maze,visited,path+'R');
        }
        //Up
        if(i-1 >= 0 && maze[i-1][j] == 1 && !visited[i-1][j]){
            dfs(i-1,j,maze,visited,path+'U');
        }
        
        //Backtrack
        visited[i][j] = 0;
    }
    
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        n = maze.size();
        if(maze[0][0] == 0 || maze[n-1][n-1] == 0)  return {};
        
        vector<vector<int>> visited(n, vector<int>(n,0));
        dfs(0,0,maze,visited,"");
        return ans;
        
    }
};