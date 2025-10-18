class Solution {
  public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        int n = edges.size();
        int m = edges[0].size();
        vector<int> adj[V];
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        queue<int> q;
        q.push(0);
        vector<int> color(V, -1);
        color[0] = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto it : adj[node]){
                //If the adjacent node is not yet colored
                //Give it the opposite color of the current node
                if(color[it] == -1){
                    color[it] = !color[node];
                    q.push(it);
                }
                //else the adj node is correct
                //check whether the adj node is of the same color or not
                else if (color[it] == color[node]){
                    return false;
                }
            }
        }
        return true;
    }
};