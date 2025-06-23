class Solution {
  public:
    vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) {
        
        int n1 = a.size();
        int n2 = b.size();
        
        
        if(n1>n2) return intersectionWithDuplicates(b,a);
        unordered_set<int> remdup(a.begin(),a.end());       //remove duplicates from a
        unordered_set<int> intersect;                       //for storing distinct numbers which are common in both
        for(auto it : b){
            if(remdup.find(it) != remdup.end()){
                intersect.insert(it);
            }
        }
        vector<int> ans(intersect.begin(),intersect.end());     //storing finasl result
        return ans;
        
        
    }
};