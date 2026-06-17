class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> distance(n, vector<int>(m, -1));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(mat[i][j] == 0){
                    distance[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        int drow[] = {-1,0,1,0};
        int dcol[]= {0,1,0,-1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i = 0; i<4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && distance[nrow][ncol] == -1){
                    distance[nrow][ncol] = distance[row][col] + 1;
                    q.push({nrow,ncol});
                }
            }
        }
        return distance;
        

    }
};

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> ans(n, vector<int> (m,-1));
        vector<vector<int>> vis(n, vector<int> (m,0));

        queue<pair<pair<int,int>,int>> q;
        //Traverse Matrix
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(mat[i][j] == 0){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
                else{
                    vis[i][j] = 0;
                }
            }
        }
        //Top right bottom down
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            ans[row][col] = dist;

            for(int i = 0; i<4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0){
                    vis[nrow][ncol] = 1;
                    q.push({{nrow,ncol},dist+1});
                }
            }
        }
        return ans;
    }
};