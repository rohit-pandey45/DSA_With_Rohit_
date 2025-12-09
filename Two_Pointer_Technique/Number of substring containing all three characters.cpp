class Solution {
public:
    int numberOfSubstrings(string s) {
        //OPTIMAL

        int n = s.size();
        vector<int> lastseen(3,-1);
        int cnt = 0;
        for(int i = 0; i<n; i++){
            lastseen[s[i] - 'a'] = i;       //seen
            if(lastseen[0] != -1 && lastseen[1] != -1 && lastseen[2] != -1){
                cnt = cnt +(1 + min(lastseen[0],min(lastseen[1],lastseen[2])));
            }
        }
        return cnt;

        //BRUTE
        // int n = s.size();
        // int cnt = 0;
        // for(int i = 0; i<n; i++){
        //     vector<int> hash(3,0);
        //     for(int j = i; j<n; j++){
        //         hash[s[j] - 'a'] = 1;
        //         if(hash[0] + hash[1] + hash[2] == 3){
        //             cnt += n-j;
        //             break;
        //         }
        //     }
        // }
        // return cnt;

    }
};