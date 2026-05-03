/**

   * Made by:    Diego Briaares
   * At:   25.09.2021 13:53:32
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
		string s;
		cin >> n >> s;
		long long C = 0;
		long long p = 1;
		int sz = (int) s.size();
		for (int i = sz - 2; i >= 0; i--) {
   			C += (long long) (s[i] - '0') * p;
   			p *= 10LL;
		}
		if (s[sz - 1] == 'G') C*= (long long) 1024;
		if (s[sz - 1] == 'T') C*= (long long) 1024 * 1024;
		vector<long long> a(n), pref(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			pref[i] = a[i];
			if (i > 0) pref[i] += pref[i - 1];
		}
		int R = 0, L = -2;
		auto ok = [&] (int le) {
			for (int i = 0; i < n; i++) {
				if (i + le - 1 >= n) break;
				long long c = pref[i + le - 1];
				if (i > 0) c -= pref[i - 1];
				if (c > C) L = i;
				if (c > C) return false;
			}
			return true;
		};
		int l = 1, r = n;
		while (l <= r) {
			int m = (l + r) / 2;
			if (ok(m)) {
				R = m;
				l = m + 1;
			}
			else {
				r = m - 1;
			}
		}
		L = -2;
		ok(R + 1);
		cout << R << " " << L + 1 << "\n";
	}