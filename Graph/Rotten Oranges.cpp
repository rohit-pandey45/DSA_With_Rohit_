class Solution {
  public:
    int orangesRotting(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        //Min time --> BFS
        queue<pair<pair<int,int>,int>> q;
        //queue((row,column),time)
        int vis[n][m];    //Initialised visited array . DONT TAKE VECTOR . ISSUE - TC
        //No of starting points = no of rotten oranges initially
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(mat[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
                else{
                    vis[i][j] = 0;
                }
            }
        }
        int time = 0;
        //Concept {top,left,bottom,right}
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            time = max(time,t);
            q.pop();
            //traverse adjacent cells
            for(int i = 0; i<4; i++){
                //new row/col = current r/c + adjustment
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                //check if that cell exists and is not visited and also that is a fresh guy not an empty guy
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol] != 2 && mat[nrow][ncol] == 1){
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol] = 2;
                }
            }
        }
        //Check if all fresh oranges are converted into rotten or not.
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(vis[i][j] != 2 && mat[i][j] == 1){
                    return -1;
                }
            }
        }
        return time;
    }
};
//TC : O(N*M) = SC