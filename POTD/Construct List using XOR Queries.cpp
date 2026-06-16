class Solution {
	public:
	vector<int> constructList(vector<vector<int>> &queries) {
		vector<long long> stored;
		long long currXor = 0;
		
		stored.push_back(0); // initial element
		
		for (auto &query : queries) {
			int type = query[0];
			long long x = query[1];
			
			if (type == 0) {
				stored.push_back(x ^ currXor);
			} else {
				currXor ^= x;
			}
		}
		
		vector<int> ans;
		for (auto v : stored) {
			ans.push_back((int)(v ^ currXor));
		}
		
		sort(ans.begin(), ans.end());
		return ans;
		
	}
};
