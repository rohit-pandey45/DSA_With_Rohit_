int spanningTree(int V, vector<vector<int>> &edges) {
    // Sort edges by weight
    sort(edges.begin(), edges.end(), [](auto &a, auto &b) {
        return a[2] < b[2];
    });

    DisjointSet ds(V);
    int mstWeight = 0;

    for (auto &it : edges) {
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        if (ds.findParent(u) != ds.findParent(v)) {
            mstWeight += wt;
            ds.unionSet(u, v);
        }
    }

    return mstWeight;
}