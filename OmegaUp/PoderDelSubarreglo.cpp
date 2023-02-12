/**

   * author:    Diego Briaares
   * At:   11.02.2023 18:25:32
**/

#include <bits/stdc++.h>
using namespace std;

void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

int BLOCKS;

	int main () {
		optimize();
		int n;
		cin >> n;
		int t;
		cin >> t;
		vector<long long> a(n + 1, 0);
		for (int i = 0; i < n; i++) {
			cin >> a[i + 1];
		}
		vector<pair<int, pair<int, int>>> seg(t);
		for (int i = 0; i < t; i++) {
			int l, r;
			cin >> l >> r;
			seg[i] = make_pair(l, make_pair(r, i));
		}
		BLOCKS = sqrt(n);
		auto BLOCK = [&] (int p) {
			return (p / BLOCKS + 1);
		};
		sort(seg.begin(), seg.end(), [&] (auto x, auto y) {
			if (BLOCK(x.first) == BLOCK(y.first)) {
				return x.second.first < y.second.first;
			}
			return BLOCK(x.first) < BLOCK(y.first);
		});
		int L, R;
		L = R = 1;
		vector<long long> freq(*max_element(a.begin(), a.end()) + 1, 0);
		freq[a[1]] = 1;
		long long ans = a[1];
		auto rem = [&] (int p) {
			ans -= a[p] * freq[a[p]] * freq[a[p]];
			freq[a[p]]--;
			ans += a[p] * freq[a[p]] * freq[a[p]];
		};
		auto add = [&] (int p) {
			ans -= a[p] * freq[a[p]] * freq[a[p]];			
			freq[a[p]]++;
			ans += a[p] * freq[a[p]] * freq[a[p]];
		};
		vector<long long> res(t);
		for (int i = 0; i < t; i++) {
			int l = seg[i].first;
			int r = seg[i].second.first;
			int qry = seg[i].second.second;
			while (L < l) {
				rem(L);
				L++;
			}
			while (L > l) {
				L--;
				add(L);
			}
			while (r < R) {
				rem(R);
				R--;
			}
			while (r > R) {
				R++;
				add(R);
			}
			res[qry] = ans;
		}
		for (int i = 0; i < t; i++) {
			cout << res[i] << "\n";
		}
	}