class Solution {
  private:
    void dfs(int node, vector<int>& vis, vector<int> adj[], stack<int>& st){
        //Mark Current Node as Visited
        vis[node] = 1;
        //Visit Neighbouring Node
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it, vis, adj, st);
            }
        }
        //Push the current node to the stack
        st.push(node);
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        //Make a Adjacency List
        vector<int> adj[V];
        for(auto& it : edges){
            adj[it[0]].push_back(it[1]); 
        }
        //Make the Visited Array
        vector<int> vis(V,0);
        stack<int> st;
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                dfs(i, vis, adj, st);
            }
        }
        //For Returning the answer
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};