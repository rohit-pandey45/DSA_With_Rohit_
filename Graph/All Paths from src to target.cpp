class Solution {
public:
    vector<vector<int>> ans;

    void dfs(int node, vector<vector<int>>& graph,
             vector<int>& path) {

        int n = graph.size();

        if(node == n - 1) {
            ans.push_back(path);
            return;
        }

        for(auto nbr : graph[node]) {
            path.push_back(nbr);

            dfs(nbr, graph, path);

            path.pop_back(); // backtrack
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

        vector<int> path;
        path.push_back(0);

        dfs(0, graph, path);

        return ans;
    }
};