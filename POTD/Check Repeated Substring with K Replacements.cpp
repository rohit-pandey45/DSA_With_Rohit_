class Solution {
  public:
    bool kSubstr(string &s, int k) {
        unordered_map<string,int> mpp;
        for(int i = 0; i<s.size(); i += k){
            mpp[s.substr(i,k)]++;
        }
        if(mpp.size() == 1) return true;
        if(mpp.size() > 2) return false;
        
        for(auto& it : mpp){
            if(it.second == 1){
                return true;
            }
        }
        return false;
        
    }
};