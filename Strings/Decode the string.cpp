
class Solution {
  public:
    string decodedString(string &s) {
        int n = s.length();
        string result = "";
        for(int i = 0; i<n; i++){
            if(s[i] != ']'){
                result.push_back(s[i]);
            }
            else{
                string str = "";
                string num = "";
                while(!result.empty() && result.back() != '['){
                    str.push_back(result.back());
                    result.pop_back();                
                }
                reverse(str.begin(),str.end());
                result.pop_back();
                while(!result.empty() && result.back() >= '0' && result.back() <= '9'){
                    num.push_back(result.back());
                    result.pop_back();
                }
                reverse(num.begin(),num.end());
                int int_num = stoi(num);
                while(int_num){
                result += str;
                int_num--;
                }
            }
        }
        
       
        return result;
    }
};