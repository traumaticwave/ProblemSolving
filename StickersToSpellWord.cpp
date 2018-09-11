static int x = []() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	return 0;
}();

class Solution {
public:
	unordered_map<string, int> um;
	int dfs(string target, vector<vector<int>> &s_map) {
		if (um.count(target)) return um[target];
		vector<int> ccnt(26, 0);
		for (auto &c : target) ccnt[c - 'a']++;

		int res = INT_MAX;
		for (int i = 0; i<s_map.size(); i++) {
			if (s_map[i][target[0] - 'a'] == 0) continue;
			string s;
			for (int j = 0; j<26; j++) {
				if (ccnt[j] - s_map[i][j]>0) s += string(ccnt[j] - s_map[i][j], 'a' + j);
			}
			int tmp = dfs(s, s_map);
			if (tmp != -1) res = min(res, tmp + 1);
		}
		um[target] = (res == INT_MAX ? -1 : res);
		return um[target];
	}

	int minStickers(vector<string>& stickers, string target) {
		um = unordered_map<string, int>();
		int len = stickers.size();
		vector<vector<int>> s_map(len, vector<int>(26, 0));
		for (int i = 0; i<len; i++) {
			for (auto &c : stickers[i])
				s_map[i][c - 'a']++;
		}
		um[""] = 0;
		return dfs(target, s_map);
	}
};