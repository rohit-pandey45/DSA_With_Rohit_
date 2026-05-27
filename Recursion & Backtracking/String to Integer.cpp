class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        
        // 1. Skip leading whitespaces
        while (i < n && s[i] == ' ') i++;
        
        // 2. Handle sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }
        
        // 3. Convert digits with overflow check
        int num = 0;
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            
            // 4. Check overflow before adding digit
            if (num > INT_MAX / 10 || 
               (num == INT_MAX / 10 && digit > 7)) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            
            num = num * 10 + digit;
            i++;
        }
        
        // 5. Apply sign
        return sign * num;
    }
};
