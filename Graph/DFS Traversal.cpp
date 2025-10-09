class Solution {
  private:
    void dfsfinder(int node, vector<vector<int>>& adj, vector<int> &vis, vector<int> &ans){
        vis[node] = 1;
        ans.push_back(node);
        for(auto it : adj[node]){
            if(!vis[it]){
                dfsfinder(it, adj, vis, ans);
            }
        }
    }
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> vis(V,0);
        int start = 0;
        vector<int> ans;
        dfsfinder(start, adj, vis, ans);
        return ans;
    }
};
//SC : O(N)     TC : O(N) + O(2E)