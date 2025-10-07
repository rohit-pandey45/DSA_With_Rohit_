#include<iostream>
using namespace std;
#include<vector>
#include<queue>


vector<int>  bfsofgraph(int n, vector<int> adj[]){
    //0 based indexing graph
    //Create a visisted array
    int vis[n] = {0};
    //Mark the starting node
    vis[0] = 1;
    //Initialise q queue data structure
    queue<int> q;
    //Pushing 0th node of the graph to the queue
    q.push(0);
    vector<int> bfs;
    //Till the queue is not empty keep popping the elements.
    while(!q.empty()){
        //Keep track of the node
        int node = q.front();
        //Pop out the node
        q.pop();
        bfs.push_back(node);
        //Visite the adjacent nodes of the recently popped out node
        for(auto it : adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                q.push(it);
            }
        }
        return bfs;
    }
}
int main(){
    int n = 5;
    vector<int> adj = {0,1,2,3,4}
    vector<int> ans = vector<int> bfsofgraph(n, adj);
    

}


//GEEKS FOR GEEKS SOLUTION

// class Solution {
//   public:
//     // Function to return Breadth First Traversal of given graph.
//     vector<int> bfs(vector<vector<int>> &adj) {
//         // Code here
//         int n = adj.size();
//         int vis[n] = {0};
//         vis[0] = 1;
//         queue<int> q;
//         q.push(0);
//         vector<int> bfs;
//         while(!q.empty()){
//             int node = q.front();
//             q.pop();
//             bfs.push_back(node);
//             for(auto it : adj[node]){
//                 // if(!vis[it]){
//                 //     vis[it] = 1;
//                 //     q.push(it);
//                 // }
//                 if(vis[it] == 0){
//                     vis[it] = 1;
//                     q.push(it);
//                 }
//             }
//         }
//         return bfs;
//     }
// };
