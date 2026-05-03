/**

   * Made by:    Diego Briaares
   * At:   13.02.2021 12:39:43
**/

#include <bits/stdc++.h>
using namespace std;


void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

	int main () {
		optimize();
		long long l, g;
		cin >> l >> g;
		long long ans = 0;
		for (int i = 0; i < g; i++)	 {
			long long p, d;
			cin >> p >> d;
			if (d) {
				ans = max(ans, l - p);
			}
			else {
				ans = max(ans, p);
			}
		}
		cout << ans << "\n"; 
	}