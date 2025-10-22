class Solution {
  public:
    bool isPossible(int N, int P, vector<pair<int, int> >& prerequisites) {
        //This can be solved in two ways
        //1. Detect a cycke using DFS
        //2. Using Topo Sort and BFS
        
        //Method - 2
        
        //Creating Adjacenecy List
        vector<int> adj[N];
        for(auto it : prerequisites){
            adj[it.first].push_back(it.second);
        }
        //Code for Topo Sort
        vector<int> inDegree(N,0);
        for(int i = 0; i<N; i++){
            for(auto it : adj[i]){
                inDegree[it]++;
            }
        }
        
        queue<int> q;
        for(int i = 0; i<N; i++){
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
        if(topo.size() == N){
            return true;
        }
        
        return false;
    }
};