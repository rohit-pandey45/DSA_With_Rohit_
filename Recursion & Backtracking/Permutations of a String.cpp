class Solution {
  public:
    void solve(string& s, vector<string>& ans, int index){
        int size = s.size();
        //Base Case
        if(index == size){
            ans.push_back(s);
            return;
        }
        //Main Logic
        unordered_set<char> st;   //For Duplicate Values
        
        for(int i = index; i<size; i++){
            if(st.count(s[i]))  continue;
            st.insert(s[i]);
            
            swap(s[i],s[index]);
            solve(s,ans,index+1);
            //BackTrack
            swap(s[i],s[index]);
        }
    }
    vector<string> findPermutation(string &s) {
        vector<string> ans;
        int index = 0;
        solve(s,ans,index);
        return ans;
    }
};
