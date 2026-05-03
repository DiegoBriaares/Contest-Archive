/**

   * Made by:    Diego Briaares
   * At:   30.10.2021 15:01:23
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
		vector<pair<int, int>> p(n);
		for (int i = 0; i < n; i++)	 cin >> p[i].first >> p[i].second;
		long long d = p[0].second;
		long long last = p[0].first;
		vector<bool> dir(2, 0);
		for (int i = 1; i < n; i++) {
			if (last + 10 > p[i].first) {
				if (d == p[i].second) {
					last = p[i].first;
				}
				else {
					dir[!d] = true;
				}
			}
			else {
				if (dir[!d]) {
					last = last + 10;
					if (p[i].second == !d) {
						last = p[i].first;
					}
					else dir[d] = true;
					dir[!d] = false;
					d = !d;
				}
				else {
					if (p[i].second == d) last = p[i].first;
					else {
						last = p[i].first;
						d = !d;
					}
				}
			}
		//	cout << "UAX: " << last << " " << d << "\n";
		}
		if (dir[!d]) last += 10;
		cout << last + 10 << "\n";
	}
