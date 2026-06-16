class Solution {
  public:
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        vector<vector<int>> ans;
        
        
        //Make Adjacency List
        vector<vector<int>> adj(V);
        for(auto& e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        //Keep Track of visited nodes
        vector<int> vis(V,false);
        
        int components = 0;
        
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                components++;
                vector<int> list;
                //BFS TRAVERSAL
                queue<int> q;
                q.push(i);
                vis[i] = true;
                
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    list.push_back(node);
                    for(auto it : adj[node]){
                        if(!vis[it]){
                            vis[it] = true;
                            q.push(it);
                        }
                    }
                }
                ans.push_back(list);
            }
        }
        return ans;
    }
};
