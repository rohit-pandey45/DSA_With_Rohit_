class Solution {
private:
    void dfs(int i, vector<int>& vis, vector<vector<int>>& isConnected, int n){
        vis[i] = 1;
        for(int j = 0; j<n; j++){
            if(isConnected[i][j] == 1 && !vis[j]){
                dfs(j,vis,isConnected,n);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n,0);
        int count = 0;
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                count++;
                dfs(i,vis,isConnected,n);
            }
        }
        return count;
    }
};