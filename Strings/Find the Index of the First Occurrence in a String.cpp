class Solution {
public:
    int strStr(string haystack, string needle) {
        // Method 1
        // return haystack.find(needle);
        // Method 2 (Sliding Window)
        int len1 = haystack.length();
        int len2 = needle.length();
        if(len2 == 0)   return 0;
        for(int i = 0; i<=len1 - len2; i++){
            if(haystack.substr(i,len2) == needle){
                return i;
            }
        }
        return -1;
    }
};