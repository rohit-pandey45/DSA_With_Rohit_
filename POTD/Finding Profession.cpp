class Solution {
public:
    string profession(int level, int pos) {
        int flips = __builtin_popcountll(pos - 1);

        return (flips & 1) ? "Doctor" : "Engineer";
    }
};