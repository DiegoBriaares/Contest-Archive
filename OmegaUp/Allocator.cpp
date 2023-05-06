/**

   * author:    Diego Briaares
   * At:   06.05.2023 15:07:08
**/

#include <bits/stdc++.h>
using namespace std;

void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

const int MAX = (int) 1e5;

struct node {
	int ans; // length of range with maximum empty space
	int pf; // length of preffix range with max empty space
	int sf;  // length of sufix range with maximum empty space.
	bool full; // is whole range empty space? 
};

node ST[4 * MAX];

int lazy[4 * MAX];

void upd(int node, int l, int r) {
	ST[node].ans = max(ST[node * 2].ans, max(ST[node * 2 + 1].ans, ST[node * 2].sf + ST[node * 2 + 1].pf));
	ST[node].pf = ST[node * 2].pf;
	if (ST[node * 2].full) {
		ST[node].pf += ST[node * 2 + 1].pf;
	}
	ST[node].sf = ST[node * 2 + 1].sf;
	if (ST[node * 2 + 1].full) {
		ST[node].sf += ST[node * 2].sf;
	}
	ST[node].full = (ST[node].ans == r - l + 1);
}

void build(int node, int l, int r) {
	if (l == r) {
		ST[node].ans = ST[node].pf = ST[node].sf = 1;
		ST[node].full = true;
		return;
	}
	if (l > r) return;
	int mid = (l + r) / 2;
	build(node * 2, l, mid);
	build(node * 2 + 1, mid + 1, r);
	upd(node, l, r);
}

void lzupd(int node, int l, int r, int t) {
	if (t == 1) {
		// Take whole space in range
		ST[node].ans = ST[node].pf = ST[node].sf = 0;
		ST[node].full = false;
	}
	else {
		// Empty whole space in range
		ST[node].ans = ST[node].pf = ST[node].sf = r - l + 1;
		ST[node].full = true;
	}
	lazy[node * 2] = lazy[node * 2 + 1] = t;
	lazy[node] = 0;
}

void Update(int node, int l, int r, int L, int R, int t) {
	if (l > r || L > R) {
		return;
	}
	if (lazy[node]) {
		lzupd(node, l, r, lazy[node]);
	}
	if (l > R || r < L) {
		return;
	}
	if (L <= l && r <= R) {
		lzupd(node, l, r, t);
		return;
	}
	int mid = (l + r) / 2;
	Update(node * 2, l, mid, L, R, t);
	Update(node * 2 + 1, mid + 1, r, L, R, t);
	upd(node, l, r);
}

int Find(int node, int l, int r, int d) {
	if (l > r) {
		return -1;
	}
	if (lazy[node]) {
		lzupd(node, l, r, lazy[node]);
	}
	if (ST[node].ans < d) {
		return -1;
	}
	if (l == r) {
		return l;
	}
	int mid = (l + r) / 2;
	int f = Find(node * 2, l, mid, d);
	if (f != -1) {
		return f;
	}
	else if (ST[node * 2].sf + ST[node * 2 + 1].pf >= d) {
		return mid - ST[node * 2].sf + 1;
	}
	else {
		return Find(node * 2 + 1, mid + 1, r, d);
	}
}

	int main () {
		optimize();
		int n, q;
		cin >> n >> q;
		build(1, 1, n);
		while (q--) {
			int t;
			cin >> t;
			int p, d;
			if (t == 1) {
				cin >> d;
				p = Find(1, 1, n, d);
				if (p == -1) {
					cout << "0\n";
				}
				else {
					Update(1, 1, n, p, p + d - 1, 1);
					cout << p << "\n";					
				}
			}
			else {
				cin >> p >> d;
				Update(1, 1, n, p, p + d - 1, 2);
			}
		}
	}