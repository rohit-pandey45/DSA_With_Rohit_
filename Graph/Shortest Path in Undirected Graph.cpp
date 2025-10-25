class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int V = adj.size();
        
        vector<int> dist(V, -1);  // -1 means unreachable
        queue<int> q;
        
        dist[src] = 0;
        q.push(src);

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(auto it : adj[node]) {
                if(dist[it] == -1) { // Not visited
                    dist[it] = dist[node] + 1;
                    q.push(it);
                }
            }
        }

        return dist;
    }
};