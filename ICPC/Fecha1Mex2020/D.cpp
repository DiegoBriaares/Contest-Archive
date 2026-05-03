/**

   * Made by:    Diego Briaares
   * At:   16.02.2021 22:22:44
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
		vector<int> b(n + 1), s(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> b[i];
			s[i] = b[i];
		}
		sort(s.begin() + 1, s.end());
		vector<bool> v(s[n] + 1, 0);
		int p = 1, ans = n;
		for (int i = 1; i <= n; i++) {
			if (p > n || v[s[p]]) break;
			if (b[i] == s[p]) {
				p++;
				ans--;
			}
			v[b[i]] = true;
		}
		cout << ans << "\n";
	}