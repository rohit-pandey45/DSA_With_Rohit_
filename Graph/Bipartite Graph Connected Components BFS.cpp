class Solution {
private:
    bool check(int start, int V, vector<vector<int>> &adj, vector<int> &color){
        queue<int> q;
        q.push(start);
        color[start] = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it : adj[node]){
                if(color[it] == -1){
                    color[it] = !color[node];
                    q.push(it);
                }
                else if (color[it] == color[node]){
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        //Calulating V
        int V = graph.size();
        // for(auto &it : graph){
        //     V = max(V, max(it[0],it[1]));
        // }
        // V = V + 1;
        //Creating Adjaency List
        // vector<int> adj[V];
        // for(auto &it : graph){
        //     adj[it[0]].push_back(it[1]);
        //     //Undirected Graph
        //     adj[it[1]].push_back(it[0]);
        // }
        //Connected Componenets
        vector<int> color(V,-1);
        for(int start = 0; start<V; start++){
            if(color[start] == -1){
                if(check(start, V, graph, color) == false){
                    return false;
                }
            }
        }
        return true;
    }
};