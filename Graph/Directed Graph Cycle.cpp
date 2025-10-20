class Solution {
  private:
    bool dfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& pathvis){
        vis[node] = 1;
        pathvis[node] = 1;
        
        for(auto it : adj[node]){
            //If Node not Visited
            if(!vis[it]){
                vis[node] = 1;
                if(dfs(it, adj, vis, pathvis) == true){
                    return true;
                }
            }
            //If path is already visited
            //But it has to be visited on the same path
            else if(pathvis[it]){
                return true;
            }
        }
        
        pathvis[node] = 0;
        return false;
    }
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        int n = edges.size();
        int m = edges[0].size();
        //Build Adjacenecy List
        vector<int> adj[V];
        for(auto& it : edges){
            adj[it[0]].push_back(it[1]);
        }
        
        vector<int> vis(V,0);
        vector<int> pathvis(V,0);
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                if(dfs(i, adj, vis, pathvis) == true){
                    return true;
                }
            }
        }
        return false;
        
    }
};