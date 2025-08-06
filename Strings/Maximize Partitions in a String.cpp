class Solution {
  public:
    int maxPartitions(string &s) {
        unordered_map<char, int> last;
        int n = s.size();

        // Step 1: store last occurrence of each character
        for (int i = 0; i < n; ++i)
            last[s[i]] = i;

        int count = 0;
        int end = 0;

        for (int i = 0; i < n; ++i) {
            end = max(end, last[s[i]]);
            if (i == end) {
                count++;
            }
        }

        return count;
    }
};
