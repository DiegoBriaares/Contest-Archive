/**

   * Made by:    Diego Briaares
   * At:   05.03.2021 20:20:58
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
		vector<pair<long long, pair<int, long long>>> f(n);	
		for (int i = 0; i < n; i++) {
			cin >> f[i].first >> f[i].second.first >> f[i].second.second;
		}
		auto check = [&] (long long k) {
			long long sum = 0;
			for (int i = 0; i < n; i++)	{
				if (f[i].first <= k) {
					sum += max(0LL, k - f[i].first - f[i].second.second) * f[i].second.first;
				}
				else {
					sum += max(0LL, f[i].first - f[i].second.second - k) * f[i].second.first;
				}
			}
			return sum;
		};
		long long l = 0, r = 1e18 + 2, la = 0;
		while (l <= r) {
			long long mid = (l + r) / 2;
			if (check(mid) > check(mid - 1)) {
				r = mid - 1;
			}
			else {
				la = mid;
				l = mid + 1;
			}
		}
		cout << check(la) << "\n";
	}