class Solution {
public:

    struct Node {
        int child[26];
        int idx;

        Node() {
            memset(child, -1, sizeof(child));
            idx = -1;
        }
    };

    vector<Node> trie;

    bool better(int a, int b, vector<string>& words) {
        if (a == -1) return true;

        if (words[b].size() < words[a].size())
            return true;

        if (words[b].size() == words[a].size() && b < a)
            return true;

        return false;
    }

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {

        trie.push_back(Node()); // root

        // Build Trie
        for (int i = 0; i < wordsContainer.size(); i++) {

            string &s = wordsContainer[i];

            int node = 0;

            // update root answer
            if (better(trie[node].idx, i, wordsContainer))
                trie[node].idx = i;

            for (int j = s.size() - 1; j >= 0; j--) {

                int c = s[j] - 'a';

                if (trie[node].child[c] == -1) {
                    trie[node].child[c] = trie.size();
                    trie.push_back(Node());
                }

                node = trie[node].child[c];

                if (better(trie[node].idx, i, wordsContainer))
                    trie[node].idx = i;
            }
        }

        vector<int> ans;

        // Query
        for (string &q : wordsQuery) {

            int node = 0;

            for (int j = q.size() - 1; j >= 0; j--) {

                int c = q[j] - 'a';

                if (trie[node].child[c] == -1)
                    break;

                node = trie[node].child[c];
            }

            ans.push_back(trie[node].idx);
        }

        return ans;
    }
};