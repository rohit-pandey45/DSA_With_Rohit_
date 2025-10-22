class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //Create Adjacency list
        vector<vector<int>> adj(numCourses);
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        //Topo Sort
        vector<int> inDegree(numCourses,0);
        for(int i = 0; i<numCourses; i++){
            for(auto it : adj[i]){
                inDegree[it]++;
            }
        }
        vector<int> topo;
        queue<int> q;
        for(int i = 0; i<numCourses; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it : adj[node]){
                inDegree[it]--;
                if(inDegree[it] == 0)   q.push(it);
            }
        }
        if(topo.size() == numCourses){
            return topo;
        }
        return {};
    }
};