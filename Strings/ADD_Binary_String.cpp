// User function template for C++
class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        int i = s1.size() - 1;      //i is initially initiased as the last index of string s1
        int j = s2.size() - 1;       //i is initially initiased as the last index of string s2
        int carry = 0;
        string result;
        while (i>=0 || j>=0 || carry>0){
            int sum = carry;
            if (i>=0){
                sum = sum + s1[i] - '0';
                i--;
            }
            if (j>=0){
                sum = sum + s2[j] - '0';
                j--;
            }
             result.push_back((sum%2) + '0');
             carry = sum/2;                     //calculating carry after adding both numbers
            }
            reverse(result.begin(),result.end());   //Leading zeros have to be removed
            while(result.length()>1 && result[0] == '0'){
                result.erase(0,1);              //Removes 1 character from index 0
            }
            return result;
        
    }
};