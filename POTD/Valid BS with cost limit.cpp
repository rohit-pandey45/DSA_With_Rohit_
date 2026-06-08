class Solution {
public:
    vector<string> ans;

    void solve(int ind, int n, int k, int cost, string& s){
        if(cost > k)    return;

        if(ind == n){
            ans.push_back(s);
            return;
        }

        s.push_back('0');
        solve(ind+1,n,k,cost,s);
        s.pop_back();
        if(ind == 0 || s.back() != '1'){
            s.push_back('1');
            solve(ind+1,n,k,cost+ind,s);
            s.pop_back();
        }
    }
    
    vector<string> generateValidStrings(int n, int k) {
        pair<int,int> p = {n,k};
        string s = "";
        solve(0,n,k,0,s);
        return ans;
    }
};