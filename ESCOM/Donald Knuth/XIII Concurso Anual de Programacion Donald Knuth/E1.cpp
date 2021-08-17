/**

   * Made by:    Diego Briaares
   * At:   13.08.2021 17:49:39
**/

#include <bits/stdc++.h>
using namespace std;


void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

	int main () {
		optimize();
		long long n;
		cin >> n;
		long long int ans = 0;
		for (int mask = 0; mask < (1 << n); mask++)	{
			int c = 0, mxx = 0, no = 0;
			for (int i = 0; i < n; i++) {
				if (mask & (1 << i)) {
					c++;
					mxx = i;
				}
			}
			for (int i = 0; i < mxx; i++) {
				if (!(mask & (1 << i))) {
					no++;
				}
			}
			ans += mxx + no - 1;
		}
		cout << ans / __gcd(ans, (1LL << n)) << "/" << (1LL << n) / __gcd(ans, (1LL << n)) << "\n";
	}