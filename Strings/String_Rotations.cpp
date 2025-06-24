
class Solution {
  public:
    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string &s1, string &s2) {
        int n = s1.length();
        string result = s1 + s1;
        //every possible rotation of s2 will be present in result
        return (result.find(s2) != string::npos);
        // npos = no position
    }
};