/**

   * author:    Diego Briaares
   * At:   02.10.2024 21:58:47
**/

#include <bits/stdc++.h>
using namespace std;

void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

	int main () {
		optimize();
		int n;
		cin >> n;
		vector<int> a(n + 1);
		for (int i = 1; i <= n; i++) {
		  cin >> a[i];
		}
			
		int sz;
		cin >> sz;
		vector<int> query(sz);
		for (int i = 0; i < sz; i++) {
			cin >> query[i];
		}

		vector<bool> L(n + 1), R(n + 1 + 1);
		L[0] = R[n + 1] = false;
		
		sort(a.begin() + 1, a.end());
		function<int(int, int, int)> r = [&](int i, int j, int q) {
			int m = i + (j - i + 1) / 2;
			R[m] = a[m] <= q;
			if (i == j) {
				return i;
			}
			else {
				if (!R[m]) {
					return r(i, m - 1, q);
				}
				else {
					return r(m, j, q);
				}
			}
		};
		
		for (int i = 0; i < sz; i++) {
			int p = r(1, n, query[i]);
			cout << (a[p] == query[i]) << " ";
		}
		cout << "\n";

	}
