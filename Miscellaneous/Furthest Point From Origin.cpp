class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();
        int cntl = 0;
        int cntr = 0;
        int cnt_ = 0;
        for (int i = 0; i<n; i++){
            if(moves[i] == 'L') cntl++;
            else if(moves[i] == 'R')    cntr++;
            else    cnt_++;
        }
        return abs(cntl - cntr) + cnt_;
    }
};