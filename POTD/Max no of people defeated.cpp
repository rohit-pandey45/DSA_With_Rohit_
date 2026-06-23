class Solution {
public:
    int maxPeopleDefeated(int p) {
        int cnt = 0;
        long long i = 1;

        while (p >= i * i) {
            p -= i * i;
            cnt++;
            i++;
        }

        return cnt;
    }
};