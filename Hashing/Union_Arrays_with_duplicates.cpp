class Solution {
  public:
    int findUnion(vector<int>& a, vector<int>& b) {
        unordered_set<int> set1;
        for(int i = 0; i<a.size(); i++){
            set1.insert(a[i]);
        }
        for(int i = 0; i<b.size(); i++){
            set1.insert(b[i]);
        }
        return set1.size();
        
    }
};