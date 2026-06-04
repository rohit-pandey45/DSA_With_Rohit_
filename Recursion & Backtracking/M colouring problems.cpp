class Solution {
  public:
  
    bool isSafe(int node, int color, vector<int>& colors, vector<vector<int>>& adj){
        for(int neigh : adj[node]){
            if(colors[neigh] == color){
                return false;
            }
        }
        return true;
    }
  
    bool solve(int node, int v, int m, vector<int>& colors, vector<vector<int>>& adj){
        if(node == v){
            return true;
        }
        for(int c = 1; c <= m; c++){
            if(isSafe(node,c,colors,adj)){
                colors[node] = c;
                if(solve(node+1,v,m,colors,adj)){
                    return true;
                }
                //Backtrack
                colors[node] = 0;
            }
            
        }
        return false;
    }
    
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        vector<vector<int>> adj(v);
        for(auto& e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> colors(v,0);
        return solve(0,v,m,colors,adj);
        
    }
};