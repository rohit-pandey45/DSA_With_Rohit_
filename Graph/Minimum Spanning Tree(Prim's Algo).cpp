class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<pair<int, int>> adj[V];
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }   
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> vis(V,0);
        int sum = 0;
        //{wt,node}
        //No need of parent node in this question
        pq.push({0,0});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int wt = it.first;
            
            if(vis[node] == 1)  continue;
            //add it to the mst
            vis[node] = 1;
            sum += wt;
            for(auto it : adj[node]){
                int adjNode = it.first;
                int edW = it.second;
                if(!vis[adjNode]){
                    pq.push({edW,adjNode});
                }
            }
        }
        return sum;
    }
};