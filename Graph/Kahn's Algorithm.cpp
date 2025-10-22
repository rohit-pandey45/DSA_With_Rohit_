class solution {
    public :
        vector<int> toposort(int V, vectro<int> adj[]){
            vector<int> inDegree(V,0);      //atleast one node will be there whose indegree will be zero
            for(int i = 0; i<V ; i++){
                for(auto it : adj[i]){
                    inDegree[it]++;
                }
            }
            queue<int> q;
            for(int i = 0; i<V ; i++){
                if(inDegree[i] == 0){
                    q.push(i);
                }
            }
            vector<int> topo;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                top.push_back(node);
                //node is in your topo sort so pls remove it from the indegree
                for(auto it : adj[node]){
                    inDegree[it]--;
                    if(inDegree[it] == 0)   q.push(it);
                }
            }
            return topo;
        }
}