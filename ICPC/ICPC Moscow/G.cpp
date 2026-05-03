/**

   * Made by:    Diego Briaares
   * At:   31.12.2021 08:47:49
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
		vector<tuple<long long, long long, long long>> a(n);
		for (int i = 0; i < n; i++)	{
			int x, y, z;
			cin >> x >> y >> z;
			a[i] = make_tuple(x, y, z);
		}
		vector<long long> op_cost(n, 0);
		for (int mask = 0; mask < (1 << 3); mask++) {
			long long mx = 0, cur;
			for (int i = 0; i < n; i++) {
				cur = 0;
				if (mask & 1) {
					cur += get<0>(a[i]);
				}
				if (mask & (1 << 1)) {
					cur += get<1>(a[i]);
				}
				if (mask & (1 << 2)) {
					cur += get<2>(a[i]);
				}
				mx = max(mx, cur);
			}
			for (int i = 0; i < n; i++) {
				cur = 0;
				if (mask & 1) {
					cur += get<0>(a[i]);
				}
				if (mask & (1 << 1)) {
					cur += get<1>(a[i]);
				}
				if (mask & (1 << 2)) {
					cur += get<2>(a[i]);
				}
				op_cost[i] = max(op_cost[i], mx - cur);
			}
		}
		long long mn = (long long) 1e18, idx = 0;
		for (int i = 0; i < n; i++) {
			if (op_cost[i] < mn) {
				mn = op_cost[i];
				idx = i;
			}
		}
		cout << mn << " " << idx + 1 << "\n";
	}

