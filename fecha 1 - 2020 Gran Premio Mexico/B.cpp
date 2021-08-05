/**

   * Made by:    Diego Briaares
   * At:   17.02.2021 01:17:14
**/

#include <bits/stdc++.h>
using namespace std;


void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

const int MAX = (int) 1e5 + 2;

long long bit[MAX];

void update(int i) {
	while (i < MAX) {
		bit[i]++; 
		i += (i & -i);
	}
}

long long query(int i) {
	long long s = 0;
	while (i > 0) {
		s += bit[i];
		i -= (i & -i);
	}
	return s;
}

	int main () {
		optimize();
		int n;
		cin >> n;
		vector<long long> a(n + 1), ans_l(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			update(a[i]);
			ans_l[i] = query(MAX - 1) - query(a[i]);
		}
		memset(bit, 0, sizeof(bit));
		long long ans_1 = 0, ans_2 = 0;
		for (int i = n; i >= 1; i--) {
			update(a[i]);
			long long ans_r = query(MAX - 1) - query(a[i]);
			ans_1 += ans_l[i];
			ans_2 += min(ans_l[i], ans_r);
		}
		cout << ans_1 << " " << ans_2 << "\n";
	}