// class Solution {
// public:
//     bool solve(int i, int open, string &s) {
//         // invalid case
//         if (open < 0) return false;

//         // reached end
//         if (i == s.size()) {
//             return open == 0;
//         }

//         if (s[i] == '(') {
//             return solve(i + 1, open + 1, s);
//         }
//         else if (s[i] == ')') {
//             return solve(i + 1, open - 1, s);
//         }
//         else { // '*'
//             return solve(i + 1, open + 1, s) ||   // '('
//                    solve(i + 1, open - 1, s) ||   // ')'
//                    solve(i + 1, open, s);         // empty
//         }
//     }

//     bool checkValidString(string s) {
//         return solve(0, 0, s);
//     }
// };
class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;

        for (char c : s) {
            if (c == '(') {
                low++;
                high++;
            } 
            else if (c == ')') {
                low--;
                high--;
            } 
            else { // '*'
                low--;      // treat as ')'
                high++;     // treat as '('
            }

            if (high < 0) return false;   // too many ')'
            if (low < 0) low = 0;         // clamp
        }

        return low == 0;
    }
};
