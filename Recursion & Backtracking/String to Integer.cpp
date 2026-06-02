class Solution{
public:
    int n = s.size();
    // Leading Spaces
    int i = 0;
    while (i < n && s[i] == ' ')
    {
        i++;
    }
    // Check for Sign
    int sign = 1; // Positive
    if (i < n && (s[i] == '+' || s[i] == '-'))
    {
        if (s[i] == '-')
        {
            sign = -1;
        }
        i++;
    }
    // Check for leading zeros
    while (i < n && s[i] == '0')
    {
        i++;
    }

    // Calculating final value
    int num = 0;
    while (i < n && isdigit(s[i]))
    {
        int digit = s[i] - '0';
        if (num > INT_MAX / 10 || (num == INT_MAX / 10 && digit > 7))
        {
            return sign == 1 ? INT_MAX : INT_MIN;
        }
        num = num * 10 + digit;
        i++;
    }
    return sign * num;


}
;
