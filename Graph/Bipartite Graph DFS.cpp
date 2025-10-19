class Solution {
  private:
    bool dfs(int node, int col , vector<int>& color, vector<int> adj[]){
        color[node] = col;
        for(auto it : adj[node]){
            if(color[it] == -1){
                if(dfs(it, !col, color, adj) == false){
                    return false;
                }
            }
            else if(color[it] == col){
                return false;
            }
        }
        return true;
    }
  public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        vector<int> adj[V];
        for(auto& it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
         vector<int> color(V,-1);
         //For Connecetd Componenets
         for(int i = 0; i<V; i++){
             if(color[i] == -1){
                 if(dfs(i, 0, color, adj) == false){
                     return false;
                 }
             }
         }
        return true;
    }
};