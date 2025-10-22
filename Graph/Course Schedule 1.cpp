class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //Created Adjacenecy List
        vector<vector<int>> adj(numCourses);
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        //Topo sort
        //Initialise InDegree Vector
        vector<int> inDegree(numCourses,0);
        for(int i = 0; i<numCourses; i++){
            for(auto it : adj[i]){
                inDegree[it]++;         //Calculate inDegree for each node
            }
        }
        //Initialise queue
        queue<int> q;
        for(int i = 0; i<numCourses; i++){
            if(inDegree[i] == 0){
                q.push(i);      //push the nodes having indegree = 0 to the queue
                //since these nodes have no incoming edges therefore we can put them anywhere at the starting of the node
            }
        }
        //Initialising topo vector
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            //push the current node to topo array
            topo.push_back(node);
            for(auto it : adj[node]){
                inDegree[it]--;                 //once inserted in topo decrease its indegree
                if(inDegree[it] == 0)   q.push(it);         //if indegree of current node = 0. push it to topo
            }
        }
        if(topo.size() == numCourses){      //all the nodes are in topo i.e. no cycle detected
            return true;
        }
        return false;
    }
};