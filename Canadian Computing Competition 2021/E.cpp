/**

   * Made by:    Diego Briaares
   * At:   05.03.2021 19:08:12
**/

#include <bits/stdc++.h>
using namespace std;


void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

long long a[200000];

long long ST[2000000];

vector<pair<long long, pair<int, int>>> q;

vector<vector<int>> upd;

void build(int l, int r, int node) {
	if (l == r) {
		ST[node] = a[l];
		return;
	}
	int mid = (l + r) / 2;
	int left = node * 2 + 1;
	int right = node * 2 + 2;
	build(l, mid, left);
	build(mid + 1, r, right);
	ST[node] = __gcd(ST[left], ST[right]);
}

int query(int l, int r, int node, int i, int j) {
	if (l > j || r < i) return 0;
	if (i <= l && r <= j) return ST[node];
	int mid = (l + r) / 2;
	int left = node * 2 + 1;
	int right = node * 2 + 2;
	return __gcd(query(l, mid, left, i, j), query(mid + 1, r, right, i, j));
}

	int main () {
		optimize();
		int n, m;
		cin >> n >> m;
		q.resize(m);
		upd.resize(17, vector<int>(n + 3, 0));
		for (int i = 0; i < m; i++) {
			cin >> q[i].second.first >> q[i].second.second >> q[i].first;
			upd[q[i].first][q[i].second.first]++;
			upd[q[i].first][q[i].second.second + 1]--;
		}
		for (int i = 1; i <= 16; i++) {
			for (int j = 1; j <= n; j++) {
				upd[i][j] += upd[i][j - 1];
			}
		}
		for (int i = 1; i <= n; i++) {
			long long lcm = 1;
			for (int j = 1; j <= 16; j++) {
				if (upd[j][i]) {
					lcm = (lcm * (long long)j) / __gcd(lcm, (long long)j);
				}                  
			}
			a[i] = lcm;
		}
		build(1, n, 0);
		for (int i = 0; i < m; i++) {
			if (query(1, n, 0, q[i].second.first, q[i].second.second) != q[i].first) {
				cout << "Impossible";
				exit(0);
			}
		}
		for (int i = 1; i <= n; i++) {
			cout << a[i];
			if (i < n) cout << " ";
		}
		exit(0);
	}