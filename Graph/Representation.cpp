//Given n = 5 nodes and m = 6 edges(Directed \ Undirected)
//set of two nodes will be provided where edges is found
//Storing - 1. Matrix 2. list
//1. Adjancey matrix
//if edge between n and m then 1 else 0
//o(n2)
#include<iostream>
using namespace std;
#include<vector>

int main(){
    int n, m;
    cin >> n >> m;
    int adj[n+1][m+1];  //1 based indexing
    for(int i =0; i<m; i++){
        int u,v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    return 0;
}
//Adjaency list o(2*no of edges)
int main(){
    int n,m;
    cin >>n >> m;
    vector<int> adj[n+1];   //1 based indexing
    for(int i = 0; i<m; i++){
        int u,v;
        cin >>u >>v ;
        adj[u].push_back(v);
        //adj[u].push_back(u);      //Directed/Undirected
    }
    return 0;
}
//Weighted Graph
// = weight