// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        //Adjacency List
        vector<pair<int,int>> adj[V];
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});  // because undirected
        }

        //Min heap -->{Dist,Node}
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(V,1e9);
        dist[src] = 0;
        pq.push({0,src});
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            //if (dis > dist[node]) continue;
            for(auto it : adj[node]){
                int edgewt = it.second;
                int adjnode = it.first;
                if(dis + edgewt < dist[adjnode]){
                    dist[adjnode] = dis + edgewt;
                    pq.push({dist[adjnode],adjnode});
                }
            }
        }
        return dist;
    }
};