class Solution {
public:
    int countCompleteComponents(int V, vector<vector<int>>& edges) {
        // Make Adjacency List
        vector<vector<int>> adj(V);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        // Keep Track of visited nodes
        vector<int> vis(V, false);

        int ans = 0;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                // BFS TRAVERSAL
                queue<int> q;
                q.push(i);
                vis[i] = true;
                int nodes = 0;
                int edgeCount = 0;
                while (!q.empty()) {
                    int node = q.front();
                    nodes++;
                    edgeCount += adj[node].size();
                    q.pop();
                    for (auto it : adj[node]) {
                        if (!vis[it]) {
                            vis[it] = true;
                            q.push(it);
                        }
                    }
                }
                edgeCount = edgeCount/2;
                long long totalEdge = 1LL*nodes*(nodes-1)/2;
                if(edgeCount == totalEdge){
                    ans++;
                }
            }
        }
        return ans;
    }
};