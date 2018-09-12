using pii = pair<int, int>;

class Solution {
public:
	int len;
	pii getxy(string str) {
		int x = 0, y = 0;
		for (int i = 0; i<str.size(); ++i)
			if (str[i] == '0') x++;
			else y++;
			return { x, y };
	}

	int findMaxForm(vector<string>& strs, int m, int n) {
		len = strs.size();
		sort(strs.begin(), strs.end(), [](string a, string b) {
			return a.size() < b.size();
		});
		vector<vector<vector<int>>> dp(len + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));

		for (int l = 1; l <= len; ++l) {
			int a, b;
			tie(a, b) = getxy(strs[l - 1]);
			for (int i = 0; i <= m; ++i) {
				for (int j = 0; j <= n; ++j) {
					dp[l][i][j] = dp[l - 1][i][j];
					if (a <= i and b <= j) dp[l][i][j] = max(dp[l][i][j], 1 + dp[l - 1][i - a][j - b]);
				}
			}
		}
		return dp[len][m][n];
	}
};