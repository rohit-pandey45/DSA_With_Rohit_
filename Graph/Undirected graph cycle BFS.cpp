class Solution {
public:
    bool bfsCycle(int src, vector<vector<int>>& adj, vector<int>& vis) {
        queue<pair<int,int>> q;

        vis[src] = 1;
        q.push({src, -1});

        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto it : adj[node]) {
                if (!vis[it]) {
                    vis[it] = 1;
                    q.push({it, node});
                }
                else if (it != parent) {
                    return true;
                }
            }
        }

        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adj(V);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(V, 0);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (bfsCycle(i, adj, vis))
                    return true;
            }
        }

        return false;
    }
};