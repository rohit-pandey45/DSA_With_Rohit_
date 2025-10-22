class Solution {
  public:
    vector<int> findOrder(int n, vector<vector<int>> prerequisites) {
        vector<int> adj[n];
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        //Code for Topo Sort
        vector<int> inDegree(n,0);
        for(int i = 0; i<n; i++){
            for(auto it : adj[i]){
                inDegree[it]++;
            }
        }
        
        queue<int> q;
        for(int i = 0; i<n; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            //Now since node is in topo so now remove it from its indegree
            for(auto it : adj[node]){
                inDegree[it]--;
                if(inDegree[it] == 0)   q.push(it);
            }
        }
        //Check if it is Directed Acyclic Graph
        if(topo.size() == n){
            return topo;
        }
        
        return {};
        
    }
};