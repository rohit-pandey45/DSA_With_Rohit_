// class Solution {
// public:
//     string removeKdigits(string num, int k) {
//         stack<char> st;
//         int n = num.size();
//         for(int i = 0; i<n; i++){
//             while(!st.empty() && k > 0 && (st.top() - '0') > (num[i] - '0')){
//                 st.pop();
//                 k--;
//             }
//             st.push(num[i]);
//         }
//         while(k>0){
//             st.pop();
//             k--;
//         }
//         if(st.empty())  return "0";
//         string res = "";
//         while(!st.empty()){
//             res = res + st.top();
//             st.pop();
//         }
//         while(res.size() != 0 && res.back() == '0'){
//             res.pop_back();
//         }
//         reverse(res.begin(), res.end());
//         int i = 0;
//         while (i < res.size() && res[i] == '0') {
//             i++;
//         }

//         res = res.substr(i); // skip all leading zeros

//         return res.empty() ? "0" : res;
//         // if(res.empty()) return "0";
//         // return res;
//     }
// };
class Solution {
public:
    string removeKdigits(string num, int k) {
        string res;

        for (char c : num) {
            // Pop back while the current digit is smaller
            // and we still have k digits to remove
            while (!res.empty() && k > 0 && res.back() > c) {
                res.pop_back();
                k--;
            }
            res.push_back(c);
        }

        // If we still have digits to remove, remove from the end
        while (k > 0 && !res.empty()) {
            res.pop_back();
            k--;
        }

        // Remove leading zeros
        int i = 0;
        while (i < res.size() && res[i] == '0') {
            i++;
        }

        res = res.substr(i);

        return res.empty() ? "0" : res;
    }
};
