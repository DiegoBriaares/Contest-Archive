/**

   * Made by:    Diego Briaares
   * At:   13.02.2021 14:17:56
**/

#include <bits/stdc++.h>
using namespace std;


void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

vector<int> edg[10000001];
pair<int, pair<int, int>> upd[1000001];
long long tree[1000001];
long long dp[1000001];

void solve(int node) {
	for (auto y : edg[node]) {
		solve(y);
		tree[node] += tree[y];
	}
}

void dfs(int node) {
	dp[node] += tree[node];
	for (auto y : edg[node]) {
		dfs(y);
		dp[node] += dp[y];
	}
}


	int main () {
		optimize();
		int n, m, q;
		cin >> n >> m >> q;
		for (int i = 1; i <= n; i++) {
			int id;
			cin >> id;
			edg[id].push_back(i);
		}
		for (int i = 1; i <= m; i++) {
			cin >> upd[i].first >> upd[i].second.first >> upd[i].second.second;
			if (upd[i].first == 2) {
				tree[upd[i].second.first] += upd[i].second.second;
			}
		}
		solve(0);
		for (int i = 1; i <= m; i++) {
			if (upd[i].first == 1) {
				tree[upd[i].second.first] += upd[i].second.second;
			}
		}
		dfs(0);
		while (q--) {
			int t, e;
			cin >> t >> e;
			if (t == 1) cout << tree[e] << "\n";
			else cout << dp[e] << "\n";
		}
	}