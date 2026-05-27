//My solution
class Solution {
public:
    vector<long long> numberOfPairs(vector<int>& nums1,
                                    vector<int>& nums2,
                                    vector<vector<int>>& queries) {

        vector<long long> ans;

        unordered_map<int,int> mpp;

        for(int num : nums2) {
            mpp[num]++;
        }

        for(auto &q : queries) {

            // Type 1 query
            if(q[0] == 1) {

                for(int i = q[1]; i <= q[2]; i++) {

                    mpp[nums2[i]]--;

                    nums2[i] += q[3];

                    mpp[nums2[i]]++;
                }
            }

            // Type 2 query
            else {

                int total = q[1];

                long long cntpairs = 0;

                for(int num : nums1) {

                    int need = total - num;

                    cntpairs += mpp[need];
                }

                ans.push_back(cntpairs);
            }
        }

        return ans;
    }
};




//accepted Solution
class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> ans;

        // 1. Calculate SQRT block sizes
        int B = sqrt(n2) + 1;
        int block_cnt = (n2 + B - 1) / B;

        // 2. Setup SQRT Decomposition structures (Using long long for tracking values)
        vector<unordered_map<long long, int>> blocks(block_cnt);
        vector<long long> lazy(block_cnt, 0);

        // Convert nums2 tracking to long long internally to avoid overflows during range adds
        vector<long long> nums2_ll(n2);
        for(int i = 0; i < n2; i++) {
            nums2_ll[i] = nums2[i];
            blocks[i / B][nums2_ll[i]]++;
        }

        // Helper lambda to rebuild a block
        auto rebuild = [&](int b) {
            blocks[b].clear();
            int start = b * B;
            int end = min(n2, start + B);
            for (int i = start; i < end; i++) {
                blocks[b][nums2_ll[i]]++;
            }
        };

        // Helper lambda to push down lazy values
        auto push = [&](int b) {
            if (lazy[b] == 0) return;
            int start = b * B;
            int end = min(n2, start + B);
            for (int i = start; i < end; i++) {
                nums2_ll[i] += lazy[b];
            }
            lazy[b] = 0;
        };

        // Track unique values of nums1 and their counts
        unordered_map<long long, int> freq1;
        for (int x : nums1) {
            freq1[x]++;
        }

        // 3. Process Queries
        for (auto &q : queries) {
            // Type 1 Query (Update)
            if (q[0] == 1) {
                int l = q[1];
                int r = q[2];
                long long val = q[3]; // Safe extension to long long

                int bl = l / B;
                int br = r / B;

                if (bl == br) {
                    push(bl);
                    for (int i = l; i <= r; i++) {
                        nums2_ll[i] += val;
                    }
                    rebuild(bl);
                } else {
                    push(bl);
                    int end_bl = (bl + 1) * B;
                    for (int i = l; i < end_bl; i++) {
                        nums2_ll[i] += val;
                    }
                    rebuild(bl);

                    push(br);
                    int start_br = br * B;
                    for (int i = start_br; i <= r; i++) {
                        nums2_ll[i] += val;
                    }
                    rebuild(br);

                    // Apply lazy updates securely
                    for (int b = bl + 1; b < br; b++) {
                        lazy[b] += val;
                    }
                }
            }
            // Type 2 Query (Count Pairs)
            else {
                long long total = q[1];
                int cntpairs = 0;

                // Loop over unique elements of nums1
                for (auto& pair : freq1) {
                    long long x = pair.first;
                    long long count_x = pair.second;
                    long long need = total - x;

                    // Search across our decomposition blocks
                    for (int b = 0; b < block_cnt; b++) {
                        long long target_val = need - lazy[b];
                        auto it = blocks[b].find(target_val);
                        if (it != blocks[b].end()) {
                            cntpairs += count_x * it->second;
                        }
                    }
                }
                ans.push_back(cntpairs);
            }
        }
        return ans;
    }
};