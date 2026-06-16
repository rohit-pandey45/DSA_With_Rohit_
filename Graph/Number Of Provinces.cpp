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

// BFS
//class Solution {
// public:
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int V = isConnected.size();
//         int provinces = 0;
//         vector<bool> vis(V,false);
//         for(int i = 0; i<V; i++){
//             if(!vis[i]){
//                 provinces++;

//                 queue<int> q;
//                 q.push(i);
//                 vis[i] = true;

//                 while(!q.empty()){
//                     int node = q.front();
//                     q.pop();
//                     for(int j = 0; j<V; j++){
//                         if(isConnected[node][j] == 1 && !vis[j]){
//                             vis[j] = true;
//                             q.push(j);
//                         }
//                     }
//                 }
//             }
//         }
//         return provinces;
//     }
// };
