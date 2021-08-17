/**

   * Made by:    Diego Briaares
   * At:   13.08.2021 15:46:20
**/

#include <bits/stdc++.h>
using namespace std;

void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

vector<pair<int, int>> upd;

const int INF = 1e9 + 1;

int lazy[6000002];
int seg_tree[6000002];

void update(int in, int fin, int node, int l, int r) {
	if (r < in || l > fin || in > fin) return;
	if (in == fin) {
		seg_tree[node] = l;
		return;
	}
	int mid = (in + fin) / 2;
	int left = node * 2 + 1;
	int right = node * 2 + 2;
	if (lazy[node]) {
		seg_tree[node] = min(seg_tree[node], lazy[node]);
		if (in != fin) {
			if (lazy[left]) lazy[left] = min(lazy[left], lazy[node]);
			else lazy[left] = lazy[node];
			if (lazy[right]) lazy[right] = min(lazy[right], lazy[node]);
			else lazy[right] = lazy[node];
		}
		lazy[node] = 0;
	}
	if (l <= in && fin <= r) {
		if (!lazy[node]) lazy[node] = l;
		else lazy[node] = min(lazy[node], l);
		return;
	}
	update(in, mid, left, l, r);
	update(mid + 1, fin, right, l, r);
}

int query(int in, int fin, int node, int l, int r) {
	if (r < in || l > fin || in > fin) return INF;
	int mid = (in + fin) / 2;
	int left = node * 2 + 1;
	int right = node * 2 + 2;
	if (lazy[node]) {
		seg_tree[node] = min(seg_tree[node], lazy[node]);
		if (in != fin) {
			if (lazy[left]) lazy[left] = min(lazy[left], lazy[node]);
			else lazy[left] = lazy[node];
			if (lazy[right]) lazy[right] = min(lazy[right], lazy[node]);
			else lazy[right] = lazy[node];
		}
		lazy[node] = 0;
	}

	if (l <= in && fin <= r) {
		return seg_tree[node];
	}
	return min(query(in, mid, left, l, r), query(mid + 1, fin, right, l, r));
}


	int main () {
		optimize();
		int n, m, q;
		cin >> n >> m >> q;
		for (int i = 0; i < 6000002; i++) seg_tree[i] = INF;
		for (int i = 0; i < m; i++)	{
			int l, r;
			cin >> l >> r;
			update(1, n, 1, l, r);
		}
		for (int i = 0; i < q; i++) {
			int u, v;
			cin >> u >> v;
			if (u > v) swap(u, v);
			if (query(1, n, 1, v, v) <= u) cout << "Yes\n";
			else cout << "No\n";
		}
	}