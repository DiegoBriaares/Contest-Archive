/**

   * Made by:    Diego Briaares
   * At:   23.10.2021 15:53:43
**/

#include <bits/stdc++.h>
using namespace std;


void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

const int MAX = 1e6;

int ST_m[4 * MAX];
int ST_M[4 * MAX];
int A[MAX];

int val;

void build_m(int l, int r, int node) {
	if (l == r) {
		ST_m[node] = A[l];
		return;
	}
	if (l > r) return;
	int mid = (l + r) / 2;
	int left = (node * 2) ;
	int right = (node * 2) + 1;
	build_m(l, mid, left);
	build_m(mid + 1, r, right);
	ST_m[node] = min(ST_m[left], ST_m[right]);
}

void build_M(int l, int r, int node) {
	if (l == r) {
		ST_M[node] = A[l];
		return;
	}
	if (l > r) return;
	int mid = (l + r) / 2;
	int left = (node * 2);
	int right = (node * 2) + 1;
	build_M(l, mid, left);
	build_M(mid + 1, r, right);
	ST_M[node] = max(ST_M[left], ST_M[right]);
}


void update_m(int l, int r, int p, int node) {
	if (l == r && l == p) {
		ST_m[node] = val;
		return;
	}
	if (l > r || l > p || r < p) return;
	int mid = (l + r) / 2;
	int left = (node * 2) ;
	int right = (node * 2) + 1;
	update_m(l, mid, p, left);
	update_m(mid + 1, r, p, right);
	ST_m[node] = min(ST_m[left], ST_m[right]);
}

void update_M(int l, int r, int p, int node) {
	if (l == r && l == p) {
		ST_M[node] = val;
		return;
	}
	if (l > r || l > p || r < p) return;
	int mid = (l + r) / 2;
	int left = (node * 2) ;
	int right = (node * 2) + 1;
	update_M(l, mid, p, left);
	update_M(mid + 1, r, p, right);
	ST_M[node] = max(ST_M[left], ST_M[right]);
}

int query_m(int l, int r, int a, int b, int node) {
	if (l > r || r < a || l > b) return MAX;
	cout << "AUX" << " " << l << " " << r << "\n";
	int mid = (l + r) / 2;
	int left = (node * 2) ;
	int right = (node * 2) + 1;
	if (a <= l && r <= b) return ST_m[node];
	return min(query_m(l, mid, a, b, left), query_m(mid + 1, r, a, b, right));
}

int query_M(int l, int r, int a, int b, int node) {
	if (l > r || r < a || l > b) return -MAX;
	int mid = (l + r) / 2;
	int left = (node * 2) ;
	int right = (node * 2) + 1;
	if (a <= l && r <= b) return ST_M[node];
	return max(query_M(l, mid, a, b, left), query_M(mid + 1, r, a, b, right));
}



	int main () {
		//optimize();
		int n, q;
		cin >> n >> q;
		for (int i = 0; i < n; i++)	{
			cin >> A[i];
		}
		build_m(0, n - 1, 0);
		build_M(0, n -1, 0);
		cout << "DEBUG\n";
		for (int i = 0; i < n; i++) cout << query_m(0, n - 1, 0, i, 0) << " ";
		cout << "\n";
		while (q--) {
			string op;
			int l, r;
			cin >> op;
			cin >> l >> r;
			if (op == "MAX") {
				cout << query_M(1, n, l - 1, r - 1, 0) << "\n";
			}
			else if (op == "MIN") {
				cout << query_m(1, n, l -1, r - 1, 0) << "\n";
			}
			else {
				val = r;
				update_m(1, n, l - 1, 0);
				update_M(1, n, l - 1, 0);
			}

		}
	}