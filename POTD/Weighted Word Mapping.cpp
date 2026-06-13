class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string s = "";
        for(auto& word : words){
            int sum = 0;
            
            for(char ch : word){
                int ind = ch - 'a';
                sum += weights[ind];
            }
            int ans = sum % 26;
            s += ('z' - ans);
        }
        return s;
    }
};