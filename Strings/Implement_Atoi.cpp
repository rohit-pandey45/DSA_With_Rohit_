class Solution {
  public:
    int myAtoi(char *s) {
        int i = 0;
        int num = 0;
        int sign = 1;
        while(s[i] == ' '){     //skip for any leading whitespaces
            i++;
        }
        if (s[i] == '+' || s[i] == '-'){        //check for a sign dafault positive
            if (s[i] == '-'){
                sign = -1;
                i++;
            }
        }
        while(s[i]>='0' && s[i]<='9'){
            if (num>(INT_MAX-(s[i]-'0'))/10)
                return sign == 1? INT_MAX:INT_MIN;
            num = num*10 +(s[i] - '0');
            i++;
        
        }
        return num*sign;
    }
};