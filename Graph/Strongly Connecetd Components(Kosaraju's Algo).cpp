//Position this line where user code will be pasted.
class Solution {
  private:
    void dfs(int node, vector<int> edges[], vector<int> &vis, stack<int> &st) {
        vis[node] = 1;
        for (auto it : edges[node]) {
            if (!vis[it])
                dfs(it, edges, vis, st);
        }
        st.push(node); // store vertex after exploring all descendants
    }
    
    // Step 3: DFS on reversed graph
    void dfsRev(int node, vector<int> adjRev[], vector<int> &vis) {
        vis[node] = 1;
        for (auto it : adjRev[node]) {
            if (!vis[it])
                dfsRev(it, adjRev, vis);
        }
    }
    
  public:
    int kosaraju(vector<vector<int>> &adj) {
        int V = adj.size();
        vector<int> edges[V];
        for(int i = 0; i<V; i++){
            for(auto it : adj[i]){
                edges[i].push_back(it);
            }
        }
        vector<int> vis(V,0);
        stack<int> st;
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                dfs(i,edges,vis,st);
            }
        }
        //Rverse the Graph
        vector<int> adjRev[V];
        for (int i = 0; i < V; i++) {
            for (auto it : edges[i]) {
                adjRev[it].push_back(i);
            }
        }
        fill(vis.begin(), vis.end(), 0);
        int scc = 0;
         while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (!vis[node]) {
                scc++;
                dfsRev(node, adjRev, vis);
            }
        }
        return scc;
    }
};