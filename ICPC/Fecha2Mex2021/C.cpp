/**

   * Made by:    Diego Briaares
   * At:   25.09.2021 12:39:51
**/

#include <bits/stdc++.h>
using namespace std;


void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

	int main () {
		optimize();
		int t;
		cin >> t;
		while (t--) {
			int n;
			string s;
			cin >> s;
			n = (int) s.size();
			vector<int> pref(n + 1, -2000000), bals(n + 1, 0);
			int bal = 0;
			bool ok = true;
			for (int i = 0; i < n; i++) {
				if (s[i] == 'R') bal++;
				else bal--;
				pref[i] = bal;
				if (bal > 0) ok = false;
				bals[i] = bal;
				if (i > 0) pref[i] = max(pref[i - 1], pref[i]);
			}
			if (ok) {
				cout << "0\n";
				continue;
			}
			vector<int> suf(n + 1, -2000000);
			for (int i = n - 1; i >= 0; i--) {
				suf[i] = max(suf[i + 1], bals[i]);
			}
			int tot_bal = bal;
			bal = 0;
			for (int i = 0; i < n; i++) {
				if ((tot_bal - bal) + pref[i] <= 0) {
					if (suf[i] - bal <= 0) {
						cout << i << "\n";
						ok = true;
						break;
					}
				}
				if (s[i] == 'R') bal++;
				else bal--;
			}
			if (!ok) cout << "-1\n";
		}
	}