/**

   * Made by:    Diego Briaares
   * At:   05.03.2021 20:41:32
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
		vector<int> r(n + 1), c(m + 1);
		int q;
		cin >> q;
		while (q--) {
   			char t;
   			int x;
   			cin >> t >> x;
   			if (t == 'R') {
   				r[x] ^= 1;
   			}
   			else {
   				c[x] ^= 1;
   			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				ans += r[i] ^ c[j];
			}
		}
		cout << ans << "\n"; 
	}