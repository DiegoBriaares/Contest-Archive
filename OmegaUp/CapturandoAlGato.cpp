/**

   * author:    Diego Briaares
   * At:   02.05.2023 11:15:50
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
		vector<int> d(n);
		int sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> d[i];
			sum += d[i];
		}
		for (int t = n; t >= 2; t--) {
			if (sum % t) {
				continue;
			}
			vector<int> edg(n, -1);
			int tg = sum / t;
			int l = 0;
			int r = 0;
			int acum = 0;
			while (l < n) {
				while (acum < tg) {
					acum += d[r];
					r = (r + 1) % n;
				}
				if (acum == tg) {
					edg[l] = r;
				}
				acum -= d[l];
				l++;
			}
			vector<bool> vis(n, false);
			for (int i = 0; i < n; i++) {
				int sz = 0;
				int cur = i;
				while (!vis[cur] && edg[cur] != -1) {
					vis[cur] = true;
					cur = edg[cur];
					sz++;
				}
				if (sz == t) {
					cout << t << "\n";
					return 0;
				}
			}
		}
		cout << "0\n";
	}