/**

   * Made by:    Diego Briaares
   * At:   13.02.2021 12:14:32
**/

#include <bits/stdc++.h>
using namespace std;


void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

	int main () {
		optimize();
		int n, m;
		cin >> n >> m;
		vector<int> a(n), b(m);
		for (int i = 0; i < n; i++)	cin >> a[i];
		for (int i = 0; i < m; i++)	cin >> b[i];
		int waste = 0;
		int x = 0, y = 0;
		while (x < n) {
			while (b[y] < a[x]) {
				waste += b[y];
				y++;
			}
			b[y] -= a[x];
			x++;
		}
		while (y < m) {
			waste += b[y];
			y++;
		}
		cout << waste << "\n";
	}