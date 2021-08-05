/**

   * Made by:    Diego Briaares
   * At:   13.02.2021 14:44:23
**/

#include <bits/stdc++.h>
using namespace std;


void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

int n, m, k, F;
int d[101];
vector<pair<int, int>> edg[101];
int f[101];
int memo[101][1500][101][2];
bool vis[101][1500][101][2];

int dp(int i, int mask, int c, bool alr) {
 	if (vis[i][mask][c][alr]) return 0;
 	if (i == 1 && mask == (1 << k) - 1) return 1;
 	if (memo[i][mask][c][alr] != -1) return memo[i][mask][c][alr];
 	vis[i][mask][c][alr] = true;
 	int ans = 0;
 	if (d[i] != -1) ans = dp(i, (mask | (1 << d[i])), c, alr);
 	if (f[i] && !alr) ans = max(ans, dp(i, mask, min(F, c + f[i]), 1));
 	for (auto y : edg[i]) {
 		if (c >= y.second) {
 			ans = max(ans, dp(y.first, mask, c - y.second, 0));
 		}
 	}
 	return ans;
} 

	int main () {
		optimize();
		cin >> n >> m >> k >> F;
		memset(d, -1, sizeof(d));
		for (int i = 0; i < k; i++) {
			int w;
			cin >> w;
			d[w] = i;
		}
		for (int i = 0; i < m; i++)	 {
			int u, v, w;
			cin >> u >> v >> w;
			edg[u].push_back({v, w});
			edg[v].push_back({u, w});
		}
		int p;
		cin >> p;
		for (int i = 0; i < p; i++) {
			int c, fu;
			cin >> c >> fu;
			f[c] = fu;
		}
		memset(memo, -1, sizeof(memo));
		int ans = 1e9;
		for (int i = 0; i <= F; i++) {
			if (dp(1, 0, i, 0)) {
				cout << i << "\n";
				return 0;
			}
		}
		cout << "-1\n";
	}