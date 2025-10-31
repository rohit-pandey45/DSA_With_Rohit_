/*Complete the functions below*/
int find(int par[], int x) {
     if (par[x] == x)
        return x;  // x is its own parent 
    
    // Path Compression — make every node on the path point directly to the root
    return par[x] = find(par, par[x]);
}

void unionSet(int par[], int x, int z) {
    int px = find(par, x);  // find parent of x
    int pz = find(par, z);  // find parent of z
    
    if (px != pz) {
        // Attach one’s parent to another’s
        par[px] = pz;  
    }
}