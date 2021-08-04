/**

   * Made by:    Diego Briaares
   * At:   03.08.2021 19:01:41
**/

#include <bits/stdc++.h>
using namespace std;


	int main () {
		int n;
		cin >> n;
		vector<pair<long long, long long>>	E(n);
		auto fix = [&] (auto x, auto y) {
			long long r = y;
			long long p = 100;
			while (x > 0) {
				r += (x % 10) * p;
				p *= 10;
				x /= 10;
			}
			return r;
		};
		for (int i = 0; i < n; i++) {
			long long a, b;
			scanf("%lld:%lld", &a, &b);
			E[i].first = fix(a, b);
			scanf("%lld:%lld", &a, &b);
			E[i].second = fix(a, b);
		}
		sort(E.begin(), E.end(), [&] (auto x, auto y) {return x.second < y.second;});
		int last = -1, ans = 0;
		for (int i = 0; i < n; i++) {
			if (E[i].first >= last) {
				ans++;
				last = E[i].second;
			}
		}
		cout << ans << "\n";
	}