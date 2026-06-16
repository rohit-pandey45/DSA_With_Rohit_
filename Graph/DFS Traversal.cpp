class Solution {
  public:
    void dfsTraversal(int node, vector<vector<int>>& adj, vector<bool>& vis, vector<int>& ans){
        vis[node] = true;
        ans.push_back(node);
        for(auto it : adj[node]){
            if(!vis[it]){
                dfsTraversal(it,adj,vis,ans);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> ans;
        vector<bool> vis(V,false);
        dfsTraversal(0,adj,vis,ans);
        return ans;
        
    }
};