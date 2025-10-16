class Solution {
  private:
    bool dfs(int node, int parent, vector<int>& vis, vector<int> adj[]){
        vis[node] = 1;
        for(auto adjacentnode : adj[node]){
            if(!vis[adjacentnode]){
                if(dfs(adjacentnode, node, vis, adj) == true){
                    return true;
                }
            }
            else if(adjacentnode != parent){
                return true;
            }
        }
        return false;
    }
        
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        //int vis[V] = {0};
        vector<int> vis(V,0);
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                 if(dfs(i, -1, vis,adj) == true){
                     return true;
                 }
            }
        }
        return false;
    }
};