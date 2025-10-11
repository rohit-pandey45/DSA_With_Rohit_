class Solution {
    private:
        bool detect(int source, vector<vector<int>>& edges, int vis[]){
            vis[source] = 1;
            //q --> {source node, parent node};
            queue<pair<int,int>> q;
            q.push({source,-1});
      
            while(!q.empty()){
            //Get current node and its Parent node
                int node = q.front().first;
                int parent = q.front().second;
                q.pop();
          
                for(auto adjacentNode : edges[node]){
                    if(!vis[adjacentNode]){
                        vis[adjacentNode] = 1;
                        q.push({adjacentNode,node});
                    }
                    else if(adjacentNode != parent){
                        return true;
                    }
                }
            }
            return false;
        }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<int> vis(V,0);
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                if(detect(i, edges, vis)){
                    return true;
                }
            }
        }
        return false;
    }
};