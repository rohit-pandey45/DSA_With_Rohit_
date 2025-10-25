// User function Template for C++
class Solution {
  private:
    void dfs(int i, vector<int>& vis, vector<pair<int,int>> adj[],stack<int>& st){
        vis[i] = 1;
        for(auto it : adj[i]){
            int v = it.first;
            if(!vis[v]){
                dfs(v,vis,adj,st);
            }
        }
        st.push(i);
    }
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        //Createing Adjacency List
        vector<pair<int,int>> adj[V];
        for(auto it : edges){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        vector<int> vis(V,0);
        stack<int> st;
        //TopoSort using DFS
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                dfs(i,vis,adj,st);
            }
        }
        //A source node is a node with no incoming edges thats why it is at the top of stack
        vector<int> dist(V, 1e9);
        dist[0] = 0;
        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (dist[node] != 1e9) {
                for (auto it : adj[node]) {
                    int v = it.first;
                    int wt = it.second;
                    if (dist[node] + wt < dist[v]) {
                        dist[v] = dist[node] + wt;
                    }
                }
            }
        }
        for (int i = 0; i < V; i++) {
            if (dist[i] == 1e9) dist[i] = -1;
        }

        return dist;

    }
};
