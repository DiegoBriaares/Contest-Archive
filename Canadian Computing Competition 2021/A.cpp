/**

   * Made by:    Diego Briaares
   * At:   05.03.2021 20:50:48
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
		vector<pair<double, double>> t(n + 1);
		for (int i = 0; i <= n; i++) {
			cin >> t[i].first;
		}
		for (int i = 0; i < n; i++) {
			cin >> t[i].second;
		}
		double ans = 0;
		for (int i = 0; i < n; i++) {
			double h = max(t[i].first, t[i + 1].first) - min(t[i].first, t[i + 1].first);
			double b = t[i].second;
			ans += b * min(t[i].first, t[i + 1].first);
			ans += (b * h) / 2.0;
		}
		cout << fixed << setprecision(9) << ans << "\n";
	}